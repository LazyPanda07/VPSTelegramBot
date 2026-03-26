#include "Serializers/ChatSerializer.h"

#include "Token.h"

namespace serializer
{
	ChatSerializer::ChatSerializer(int64_t chatId) :
		chatId(chatId)
	{

	}

	framework::JsonObject ChatSerializer::serializeArguments() const
	{
		framework::JsonObject result;

		result["chatId"] = chatId;
		result["token"] = token;

		return result;
	}

	std::string_view ChatSerializer::getTaskExecutorName() const
	{
		return "NetworkSpeedTest";
	}
}
