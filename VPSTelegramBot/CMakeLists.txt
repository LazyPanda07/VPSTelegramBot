cmake_minimum_required(VERSION 3.27.0)

project(VPSTelegramBot)

find_package(WebFramework REQUIRED)

add_executable(
	${PROJECT_NAME}
	src/main.cpp
	src/Executors/HelloExecutor.cpp
	src/TaskExecutors/NetworkSpeedTest.cpp
)

target_link_libraries(
	${PROJECT_NAME} PRIVATE
	WebFramework::CXX_API
)
