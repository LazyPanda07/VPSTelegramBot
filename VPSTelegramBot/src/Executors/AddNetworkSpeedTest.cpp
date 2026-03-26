#include "Executors/AddNetworkSpeedTest.h"

#include <fstream>

#include "Serializers/ChatSerializer.h"

namespace executor
{
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
			request.enqueueTask<framework::task_broker::Internal, serializer::ChatSerializer>(chatId);

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
