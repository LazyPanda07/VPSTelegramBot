#pragma once

#include <TaskBroker/TaskExecutor.hpp>

namespace task_executor
{
	class NetworkSpeedTest : public framework::task_broker::TaskExecutor
	{
	public:
		void operator ()(const framework::JsonObject& data) override;
	};
}
