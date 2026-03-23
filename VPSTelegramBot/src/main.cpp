#include <iostream>

#include <import.hpp>

#include "Token.h"

int main(int argc, char** argv) try
{
	if (argc != 2)
	{
		std::cerr << "No token provided" << std::endl;

		return 1;
	}

	token = argv[1];

	framework::utility::initializeWebFramework();

	framework::utility::Config config("config.json");
	framework::WebFramework server(config);

	server.start(true, []() { std::cout << "Server is running..." << std::endl; });

	return 0;
}
catch (const std::exception& e)
{
	std::cerr << e.what() << std::endl;

	return 2;
}
