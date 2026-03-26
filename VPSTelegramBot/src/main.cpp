#include <iostream>

#include <import.hpp>

#include "Globals.h"

int main(int argc, char** argv) try
{
	std::string certPath;
	std::string keyPath;

	if (const char* temp = std::getenv("TOKEN"))
	{
		token = temp;
	}
	else
	{
		throw std::runtime_error("Can't find TOKEN variable");
	}

	if (const char* temp = std::getenv("CERT_PATH"))
	{
		certPath = temp;
	}
	else
	{
		throw std::runtime_error("Can't find CERT_PATH variable");
	}

	if (const char* temp = std::getenv("KEY_PATH"))
	{
		keyPath = temp;
	}
	else
	{
		throw std::runtime_error("Can't find KEY_PATH variable");
	}

	if (const char* temp = std::getenv("USER_AGENT_FILTER"))
	{
		userAgentFilter = temp;
	}
	else
	{
		throw std::runtime_error("Can't find USER_AGENT_FILTER variable");
	}

	framework::utility::initializeWebFramework();

	framework::utility::Config config("config.json");

	config.overrideConfiguration("pathToCertificate", certPath);
	config.overrideConfiguration("pathToKey", keyPath);

	server = std::make_unique<framework::WebFramework>(config);
	
	server->start(true, []() { std::cout << "Server is running..." << std::endl; });

	return 0;
}
catch (const std::exception& e)
{
	std::cerr << e.what() << std::endl;

	return 1;
}
