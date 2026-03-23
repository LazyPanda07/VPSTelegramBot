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
	${NETWORKS_INCLUDE_DIRECTORIES}
)

target_link_libraries(
	${PROJECT_NAME} PRIVATE
	WebFramework::CXX_API
	Networks
	JSON
	HTTP
	SocketStreams
	ssl
	crypto
)

target_link_directories(
	${PROJECT_NAME} PRIVATE
	${NETWORKS_LINK_DIRECTORIES}
)

if (WIN32)
	target_link_libraries(
		${PROJECT_NAME} PRIVATE
		crypt32
	)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION .)
install(DIRECTORY settings/ DESTINATION .)
