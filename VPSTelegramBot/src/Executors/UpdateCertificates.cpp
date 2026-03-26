#include "Executors/UpdateCertificates.h"

#include <filesystem>
#include <fstream>

#include "Globals.h"

namespace executor
{
	void UpdateCertificates::doPost(framework::HttpRequest& request, framework::HttpResponse& response)
	{
		if (request.getHeaders().at("User-Agent") != userAgentFilter)
		{
			request.throwException("Can't process request", framework::ResponseCodes::badRequest, "LogUpdateCertificates");
		}

		for (const framework::Multipart& multipart : request.getMultiparts())
		{
			std::ofstream file(std::filesystem::path("/certs") / multipart.getName());
			const std::string& data = multipart.getData();

			file.write(data.data(), data.size());
		}

		server->updateSslCertificates();
	}

	DEFINE_EXECUTOR(UpdateCertificates)
}
