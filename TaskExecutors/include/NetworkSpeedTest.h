#pragma once

#include <TaskBroker/TaskExecutor.hpp>

namespace task_executor
{
	class NetworkSpeedTest : public framework::task_broker::TaskExecutor
	{
	public:
		void execute(const framework::JsonObject& data, const framework::task_broker::TaskExecutor::TaskExecutorContext& context) override;
	};
}
