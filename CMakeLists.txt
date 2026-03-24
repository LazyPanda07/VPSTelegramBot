cmake_minimum_required(VERSION 3.27.0)

set(NETWORKS_INCLUDE_DIRECTORIES "" CACHE INTERNAL "")
set(NETWORKS_LINK_DIRECTORIES "" CACHE INTERNAL "")
set(BASE_TCP_SERVER_INCLUDE_DIRECTORIES "" CACHE INTERNAL "")
set(BASE_TCP_SERVER_LINK_DIRECTORIES "" CACHE INTERNAL "")

project(VPSTelegramBotProject)

if (WIN32)
	add_definitions(-DWIN32_LEAN_AND_MEAN)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_subdirectory(FetchWebFramework)
add_subdirectory(FetchNetworks)
add_subdirectory(FetchBaseTCPServer)

add_subdirectory(TaskExecutors)
add_subdirectory(VPSTelegramBot)
