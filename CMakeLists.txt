cmake_minimum_required(VERSION 3.2.1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/staticlibs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/staticlibs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra")

project(Silent_Log)

### Includes ###
include_directories(.)

### Sources ###
set(C_SOURCES ${SOURCES} log.c)
set(CPP_SOURCES ${SOURCES} log.cpp)
add_library(Silent_Log_C STATIC ${C_SOURCES})
add_library(Silent_Log_Cpp STATIC ${CPP_SOURCES})

set(TEST_C_SOURCES tests/test_c_log.c)
set(TEST_CPP_SOURCES tests/test_cpp_log.cpp)

add_executable(Silent_Log_C_Test ${TEST_C_SOURCES})
add_executable(Silent_Log_Cpp_Test ${TEST_CPP_SOURCES})

install(TARGETS Silent_Log_C_Test DESTINATION bin)
install(TARGETS Silent_Log_Cpp_Test DESTINATION bin)

target_link_libraries(Silent_Log_C_Test Silent_Log_C)
target_link_libraries(Silent_Log_Cpp_Test Silent_Log_Cpp)

