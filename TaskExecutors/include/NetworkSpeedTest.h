#pragma once

#include <TaskBroker/TaskExecutor.hpp>

#include <random>
#include <mutex>

namespace task_executor
{
	class NetworkSpeedTest : public framework::task_broker::TaskExecutor
	{
	private:
		std::string generateResultFile();

	private:
		std::mt19937_64 random;
		std::mutex generateMutex;

	public:
		void execute(const framework::JsonObject& data, const framework::task_broker::TaskExecutor::TaskExecutorContext& context) override;
	};
}
