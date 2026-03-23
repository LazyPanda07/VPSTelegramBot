#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>

#include <import.hpp>
#include <BaseTCPServer.h>

#include "Token.h"

class UpdateCertificatesServer : public web::BaseTCPServer
{
private:
	framework::WebFramework& server;

private:
	void clientConnection(const std::string& ip, SOCKET clientSocket, sockaddr address, std::function<void()>& cleanup) override
	{
		constexpr size_t defaultSize = 64;

		std::string updateCommand(defaultSize, '\0');

		BaseTCPServer::receiveBytes(clientSocket, updateCommand.data(), static_cast<int>(updateCommand.size()));

		if (updateCommand == "update certificates")
		{
			server.updateSslCertificates();
		}
	}

public:
	UpdateCertificatesServer(framework::WebFramework& server) :
		BaseTCPServer("4923", "0.0.0.0", 0UL, false, 0UL, false),
		server(server)
	{

	}

	~UpdateCertificatesServer() = default;
};

int main(int argc, char** argv) try
{
	if (const char* temp = std::getenv("TOKEN"))
	{
		token = temp;
	}
	else
	{
		std::cerr << "Can't find TOKEN variable" << std::endl;

		return 1;
	}

	framework::utility::initializeWebFramework();

	framework::utility::Config config("config.json");
	framework::WebFramework server(config);
	UpdateCertificatesServer updateCertificatesServer(server);

	updateCertificatesServer.start();
	server.start(true, []() { std::cout << "Server is running..." << std::endl; });

	return 0;
}
catch (const std::exception& e)
{
	std::cerr << e.what() << std::endl;

	return 2;
}
