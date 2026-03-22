#include "Executors/HelloExecutor.h"

namespace executor
{
	void HelloExecutor::doGet(framework::HttpRequest& request, framework::HttpResponse& response)
	{
		framework::JsonBuilder builder;

		builder["message"] = "Hello, World!";

		response.setBody(builder);
	}

	DEFINE_EXECUTOR(HelloExecutor);
}
