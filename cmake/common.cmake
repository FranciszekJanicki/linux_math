include_guard(GLOBAL)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(MAIN_DIR ${PROJECT_DIR}/main)
set(CMAKE_DIR ${PROJECT_DIR}/cmake)
set(COMPONENTS_DIR ${PROJECT_DIR}/components)
set(SUBMODULES_DIR ${PROJECT_DIR}/submodules)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

if(NOT CMAKE_PROJECT_NAME)
    set(CMAKE_PROJECT_NAME project)
endif()

message(STATUS "Project name: ${CMAKE_PROJECT_NAME}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")