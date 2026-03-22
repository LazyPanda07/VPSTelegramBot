#include "NetworkSpeedTest.h"

namespace task_executor
{
	void NetworkSpeedTest::operator ()(const framework::JsonObject& data)
	{
		int64_t chatId;

		data.tryGet<int64_t>("chatId", chatId);

		// TODO: run speedtest
	}

	DEFINE_TASK_EXECUTOR(NetworkSpeedTest)
}
