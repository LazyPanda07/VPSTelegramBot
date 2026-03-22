#include "Executors/AddNetworkSpeedTest.h"

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
	void AddNetworkSpeedTest::doPost(framework::HttpRequest& request, framework::HttpResponse& response)
	{
		request.enqueueTask<framework::task_broker::Internal, UserSerializer>(request.getJson().get<framework::JsonObject>("message")["from"]["id"].get<int64_t>());

		response.setResponseCode(framework::ResponseCodes::accepted);
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

	return result;
}

std::string_view UserSerializer::getTaskExecutorName() const
{
	return "NetworkSpeedTest";
}
