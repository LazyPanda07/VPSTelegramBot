cmake_minimum_required(VERSION 3.27.0)

project(TaskExecutors)

find_package(WebFramework REQUIRED)

add_library(
	${PROJECT_NAME} SHARED
	src/NetworkSpeedTest.cpp
)

target_include_directories(
	${PROJECT_NAME} PRIVATE
	include
)

target_link_libraries(
	${PROJECT_NAME} PRIVATE
	WebFramework::CXX_API
)

install(TARGETS ${PROJECT_NAME} DESTINATION .)
install(DIRECTORY settings/ DESTINATION .)
