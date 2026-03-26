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
		int64_t chatId;
		std::string token;
		std::string response;
		streams::IOSocketStream stream = streams::IOSocketStream::createStream<web::HttpsNetwork>("api.telegram.org");
		std::string resultFile = this->generateResultFile();
		json::JsonBuilder result(CP_UTF8);
		
		data.tryGet<int64_t>("chatId", chatId);
		data.tryGet<std::string>("token", token);

		int errorCode = std::system(std::format("speedtest --simple > {}", resultFile).data());
		std::string text = (std::ostringstream() << std::ifstream(resultFile).rdbuf()).str();

		if (errorCode)
		{
			text += std::format("\nError code: {}", errorCode);
		}

		result["chat_id"] = chatId;
		result["text"] = text;

		std::string request = web::HttpBuilder()
			.postRequest()
			.headers("Host", "api.telegram.org")
			.parameters(std::format("bot{}/sendMessage", token))
			.build(result);

		stream << request;

		stream >> response;

		std::filesystem::remove(resultFile);
	}

	DEFINE_TASK_EXECUTOR(NetworkSpeedTest)
}
