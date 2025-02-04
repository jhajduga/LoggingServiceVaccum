cmake_minimum_required(VERSION 3.10)
project(LogSvcExampleApp)

#----------------------------------------------------------------------------
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_definitions(LOGURU_USE_FMTLIB=1)

#----------------------------------------------------------------------------
# Define project directories
set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(EXAMPLES_DIR "${PROJECT_SOURCE_DIR}/examples")
set(TESTS_DIR "${PROJECT_SOURCE_DIR}/tests")
set(EXTERNALS_DIR "${PROJECT_SOURCE_DIR}/externals")
add_definitions(-DPROJECT_LOCATION_PATH=\"${PROJECT_SOURCE_DIR}\")
#----------------------------------------------------------------------------
# Add subdirectories
add_subdirectory(${SRC_DIR})
add_subdirectory(${EXAMPLES_DIR})
add_subdirectory(${TESTS_DIR})
