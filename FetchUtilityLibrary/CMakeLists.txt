cmake_minimum_required(VERSION 4.0.0)

set(UTILITY_LIBRARY_VERSION 0.12.1)
set(UTILITY_LIBRARY_URL https://github.com/LazyPanda07/UtilityLibrary/releases/download/v${UTILITY_LIBRARY_VERSION})
set(FETCHCONTENT_QUIET OFF CACHE BOOL "")

project(FetchUtilityLibrary)

include(FetchContent)

if (UNIX)
    set(UTILITY_LIBRARY_URL ${UTILITY_LIBRARY_URL}/linux.zip)
else()
    set(UTILITY_LIBRARY_URL ${UTILITY_LIBRARY_URL}/windows.zip)
endif()

FetchContent_Declare(
    UtilityLibrary
    URL ${UTILITY_LIBRARY_URL}
)

FetchContent_MakeAvailable(UtilityLibrary)

if (UNIX)
    set(UTILITY_LIBRARY_INCLUDE_DIRECTORIES ${utilitylibrary_SOURCE_DIR}/include)
    set(UTILITY_LIBRARY_LINK_DIRECTORIES ${utilitylibrary_SOURCE_DIR}/lib)
else()
    set(UTILITY_LIBRARY_INCLUDE_DIRECTORIES ${utilitylibrary_SOURCE_DIR}/${CMAKE_BUILD_TYPE}_Windows/include)
    set(UTILITY_LIBRARY_LINK_DIRECTORIES ${utilitylibrary_SOURCE_DIR}/${CMAKE_BUILD_TYPE}_Windows/lib)
endif()

set(UTILITY_LIBRARY_LINK_DIRECTORIES ${UTILITY_LIBRARY_LINK_DIRECTORIES} CACHE INTERNAL "")
set(UTILITY_LIBRARY_INCLUDE_DIRECTORIES ${UTILITY_LIBRARY_INCLUDE_DIRECTORIES} CACHE INTERNAL "")
