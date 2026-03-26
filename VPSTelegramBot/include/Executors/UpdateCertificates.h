#pragma once

#include <Executors/StatelessExecutor.hpp>

namespace executor
{
	class UpdateCertificates : public framework::StatelessExecutor
	{
	public:
		void doPost(framework::HttpRequest& request, framework::HttpResponse& response) override;
	};
}
