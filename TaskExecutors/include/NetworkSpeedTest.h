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
		void operator ()(const framework::JsonObject& data) override;
	};
}
