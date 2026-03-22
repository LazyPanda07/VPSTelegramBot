#include "Executors/HelloExecutor.h"

#include <iostream>

namespace executor
{
	void HelloExecutor::doPost(framework::HttpRequest& request, framework::HttpResponse& response)
	{
		framework::JsonParser data = request.getJson();

		std::cout << data << std::endl;

		response.setBody("Hello");
	}

	DEFINE_EXECUTOR(HelloExecutor);
}
