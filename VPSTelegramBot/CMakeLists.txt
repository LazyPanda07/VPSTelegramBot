cmake_minimum_required(VERSION 3.27.0)

include(${WEB_FRAMEWORK_SDK}/WebFrameworkConfig.cmake)

project(VPSTelegramBot)

add_executable(
	${PROJECT_NAME}
	src/main.cpp
	src/Executors/HelloExecutor.cpp
	srsc/TaskExecutors/NetworkSpeedTest.cpp
)

target_link_libraries(
	${PROJECT_NAME} PRIVATE
	WebFramework::CXX_API
)
