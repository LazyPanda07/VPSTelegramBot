cmake_minimum_required(VERSION 3.27.0)

set(NETWORKS_VERSION 1.25.0)
set(NETWORKS_URL https://github.com/LazyPanda07/Networks/releases/download/v${NETWORKS_VERSION})
set(FETCHCONTENT_QUIET OFF CACHE BOOL "")

project(FetchNetworks)

include(FetchContent)

if (UNIX)
    set(NETWORKS_URL ${NETWORKS_URL}/linux.zip)
else()
    set(NETWORKS_URL ${NETWORKS_URL}/windows.zip)
endif()

FetchContent_Declare(
    Networks
    URL ${NETWORKS_URL}
)

FetchContent_MakeAvailable(Networks)

if (UNIX)
    set(NETWORKS_INCLUDE_DIRECTORIES ${networks_SOURCE_DIR}/Release_Linux/include)
    set(NETWORKS_LINK_DIRECTORIES ${networks_SOURCE_DIR}/Release_Linux/lib)
else()
    set(NETWORKS_INCLUDE_DIRECTORIES ${networks_SOURCE_DIR}/${CMAKE_BUILD_TYPE}_Windows/include)
    set(NETWORKS_LINK_DIRECTORIES ${networks_SOURCE_DIR}/${CMAKE_BUILD_TYPE}_Windows/lib)
endif()

set(NETWORKS_LINK_DIRECTORIES ${NETWORKS_LINK_DIRECTORIES} CACHE INTERNAL "")
set(NETWORKS_INCLUDE_DIRECTORIES ${NETWORKS_INCLUDE_DIRECTORIES} CACHE INTERNAL "")
