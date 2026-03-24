#include "Executors/AddNetworkSpeedTest.h"

#include <fstream>

#include "Token.h"

class UserSerializer : public framework::task_broker::TaskSerializer<>
{
private:
	int64_t chatId;

private:
	framework::JsonObject serializeArguments() const override;
	
	std::string_view getTaskExecutorName() const override;

public:
	UserSerializer(int64_t chatId);

	~UserSerializer() = default;
};

namespace executor
{
	void AddNetworkSpeedTest::doGet(framework::HttpRequest& request, framework::HttpResponse& response)
	{
		framework::JsonBuilder result;

		result["message"] = "Hello, World!";

		response.setBody(result);
	}

	void AddNetworkSpeedTest::doPost(framework::HttpRequest& request, framework::HttpResponse& response)
	{
		const framework::JsonParser& json = request.getJson();
		framework::JsonObject message = json.get<framework::JsonObject>("message");
		int64_t chatId = message["from"]["id"].get<int64_t>();
		framework::JsonBuilder result;
		std::string messageText;

		result["method"] = "sendMessage";
		result["chat_id"] = chatId;

		if (message.tryGet<std::string>("text", messageText) && messageText == "/check_speed")
		{
			request.enqueueTask<framework::task_broker::Internal, UserSerializer>(chatId);

			result["text"] = "Start checking network speed...";
		}
		else
		{
			result["text"] = "Wrong command. Only /check_speed available";
		}

		response.setBody(result);
	}

	DEFINE_EXECUTOR(AddNetworkSpeedTest);
}

UserSerializer::UserSerializer(int64_t chatId) :
	chatId(chatId)
{

}

framework::JsonObject UserSerializer::serializeArguments() const
{
	framework::JsonObject result;

	result["chatId"] = chatId;
	result["token"] = token;

	return result;
}

std::string_view UserSerializer::getTaskExecutorName() const
{
	return "NetworkSpeedTest";
}
