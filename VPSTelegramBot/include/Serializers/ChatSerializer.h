#pragma once

#include <TaskBroker/TaskSerializer.hpp>

namespace serializer
{
	class ChatSerializer : public framework::task_broker::TaskSerializer<>
	{
	private:
		int64_t chatId;

	private:
		framework::JsonObject serializeArguments() const override;

		std::string_view getTaskExecutorName() const override;

	public:
		ChatSerializer(int64_t chatId);

		~ChatSerializer() = default;
	};
}
