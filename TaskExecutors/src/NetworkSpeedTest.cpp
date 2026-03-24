#include "NetworkSpeedTest.h"

#include <format>
#include <filesystem>

#include <IOSocketStream.h>
#include <HttpBuilder.h>
#include <HttpsNetwork.h>

namespace task_executor
{
	std::string NetworkSpeedTest::generateResultFile()
	{
		std::lock_guard<std::mutex> lock(generateMutex);

		return std::format("result_{}.txt", random());
	}

	void NetworkSpeedTest::operator ()(const framework::JsonObject& data)
	{
		std::string resultFile = this->generateResultFile();
		int64_t chatId;
		std::string token;
		
		data.tryGet<int64_t>("chatId", chatId);
		data.tryGet<std::string>("token", token);

		int errorCode = std::system(std::format("speedtest --simple > {}", resultFile).data());

		if (!errorCode)
		{
			streams::IOSocketStream stream = streams::IOSocketStream::createStream<web::HttpsNetwork>("api.telegram.org");
			json::JsonBuilder result(CP_UTF8);
			std::string response;
			std::string speedtestData;
			
			{
				std::ifstream stream(resultFile);
				std::string temp;

				while (std::getline(stream, temp))
				{
					speedtestData += temp + R"(\n)";
				}
			}

			result["chat_id"] = chatId;
			result["text"] = speedtestData;

			std::string request = web::HttpBuilder()
				.postRequest()
				.headers("Host", "api.telegram.org")
				.parameters(std::format("bot{}/sendMessage", token))
				.build(result);

			std::ofstream("request.txt") << request;

			stream << request;

			stream >> response;

			std::ofstream("response.txt") << response;
		}

		std::filesystem::remove(resultFile);
	}

	DEFINE_TASK_EXECUTOR(NetworkSpeedTest)
}
