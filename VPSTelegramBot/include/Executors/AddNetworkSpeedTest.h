#pragma once

#include <Executors/StatelessExecutor.hpp>

namespace executor
{
	class AddNetworkSpeedTest : public framework::StatelessExecutor
	{
	public:
		void doPost(framework::HttpRequest& request, framework::HttpResponse& response) override;
	};
}
