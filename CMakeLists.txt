cmake_minimum_required(VERSION 3.14)
project(Alpha2Hex VERSION 1.1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

configure_file (
        "${PROJECT_SOURCE_DIR}/include/alpha2hex/version.h.in"
        "${PROJECT_SOURCE_DIR}/include/alpha2hex/version.h"
)

include(FetchContent)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

add_subdirectory(src)
add_subdirectory(apps)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
