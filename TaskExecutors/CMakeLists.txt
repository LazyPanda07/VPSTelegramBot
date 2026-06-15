cmake_minimum_required(VERSION 4.0.0)

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
	${UTILITY_LIBRARY_INCLUDE_DIRECTORIES}
)

target_link_libraries(
	${PROJECT_NAME} PRIVATE
	WebFramework::CXX_API
	Networks
	JSON
	HTTP
	SocketStreams
	UtilityLibrary
	ssl
	crypto
)

target_link_directories(
	${PROJECT_NAME} PRIVATE
	${NETWORKS_LINK_DIRECTORIES}
	${UTILITY_LIBRARY_LINK_DIRECTORIES}
)

if (UNIX)
	target_link_libraries(
		${PROJECT_NAME} PRIVATE
		uuid
	)
elseif (WIN32)
	target_link_libraries(
		${PROJECT_NAME} PRIVATE
		crypt32
		Rpcrt4
	)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION .)
install(DIRECTORY settings/ DESTINATION .)
