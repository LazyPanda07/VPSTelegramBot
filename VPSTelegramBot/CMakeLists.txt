cmake_minimum_required(VERSION 3.27.0)

project(VPSTelegramBot)

find_package(WebFramework REQUIRED)

add_executable(
	${PROJECT_NAME}
	src/main.cpp
	src/Executors/AddNetworkSpeedTest.cpp
)

target_include_directories(
	${PROJECT_NAME} PRIVATE
	include
	${BASE_TCP_SERVER_INCLUDE_DIRECTORIES}
)

target_link_libraries(
	${PROJECT_NAME} PRIVATE
	WebFramework::CXX_API
	BaseTCPServer
)

target_link_directories(
	${PROJECT_NAME} PRIVATE
	${BASE_TCP_SERVER_LINK_DIRECTORIES}
)

if (UNIX)
	target_link_options(
		${PROJECT_NAME} PRIVATE
		-rdynamic
	)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION .)
install(DIRECTORY settings/ DESTINATION .)
install(FILES config.json DESTINATION .)
