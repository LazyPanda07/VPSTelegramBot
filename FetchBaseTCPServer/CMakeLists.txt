cmake_minimum_required(VERSION 3.27.0)

set(BASE_TCP_SERVER_VERSION 1.17.1)
set(BASE_TCP_SERVER_URL https://github.com/LazyPanda07/BaseTCPServer/releases/download/v${BASE_TCP_SERVER_VERSION})
set(FETCHCONTENT_QUIET OFF CACHE BOOL "")

project(FetchBaseTCPServer)

include(FetchContent)

if (UNIX)
    set(BASE_TCP_SERVER_URL ${BASE_TCP_SERVER_URL}/linux.zip)
else()
    set(BASE_TCP_SERVER_URL ${BASE_TCP_SERVER_URL}/windows.zip)
endif()

FetchContent_Declare(
    BaseTCPServer
    URL ${BASE_TCP_SERVER_URL}
)

FetchContent_MakeAvailable(BaseTCPServer)

if (UNIX)
    set(BASE_TCP_SERVER_INCLUDE_DIRECTORIES ${networks_SOURCE_DIR}/Release_Linux/include)
    set(BASE_TCP_SERVER_LINK_DIRECTORIES ${networks_SOURCE_DIR}/Release_Linux/lib)
else()
    set(BASE_TCP_SERVER_INCLUDE_DIRECTORIES ${networks_SOURCE_DIR}/${CMAKE_BUILD_TYPE}_Windows/include)
    set(BASE_TCP_SERVER_LINK_DIRECTORIES ${networks_SOURCE_DIR}/${CMAKE_BUILD_TYPE}_Windows/lib)
endif()

set(BASE_TCP_SERVER_LINK_DIRECTORIES ${BASE_TCP_SERVER_LINK_DIRECTORIES} CACHE INTERNAL "")
set(BASE_TCP_SERVER_INCLUDE_DIRECTORIES ${BASE_TCP_SERVER_INCLUDE_DIRECTORIES} CACHE INTERNAL "")
