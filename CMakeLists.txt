cmake_minimum_required(VERSION 3.27.0)

set(NETWORKS_LINK_DIRECTORIES "" CACHE INTERNAL "")
set(NETWORKS_INCLUDE_DIRECTORIES "" CACHE INTERNAL "")
set(BASE_TCP_SERVER_LINK_DIRECTORIES "" CACHE INTERNAL "")
set(BASE_TCP_SERVER_INCLUDE_DIRECTORIES "" CACHE INTERNAL "")

project(VPSTelegramBotProject)

add_subdirectory(FetchWebFramework)
add_subdirectory(FetchNetworks)
add_subdirectory(FetchBaseTCPServer)

add_subdirectory(TaskExecutors)
add_subdirectory(VPSTelegramBot)
