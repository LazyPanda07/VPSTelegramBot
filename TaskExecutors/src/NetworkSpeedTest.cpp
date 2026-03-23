#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#endif

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
			
			result["chat_id"] = chatId;
			result["text"] = (std::ostringstream() << std::ifstream(resultFile).rdbuf()).str();

			std::string httpBody = web::HttpBuilder()
				.postRequest()
				.parameters(std::format("bot{}/sendMessage", token))
				.build(result);

			std::ofstream("request.txt") << httpBody;

			stream << httpBody;

			stream >> response;

			std::ofstream("response.txt") << response;
		}
		else
		{
			std::ofstream(std::format("{}.log", resultFile)) << "Error code: " << errorCode << std::endl;
		}

		std::filesystem::remove(resultFile);
	}

	DEFINE_TASK_EXECUTOR(NetworkSpeedTest)
}
