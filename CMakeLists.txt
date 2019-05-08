cmake_minimum_required(VERSION 2.8)

project(kafkaclient-cpp)
set(OUTPUT_NAME ${PROJECT_NAME})

add_definitions(-fvisibility=hidden)
add_definitions(-D__LINUX64__)
add_definitions(-fPIC)
add_definitions(-Wno-write-strings)
add_definitions(-std=c++11)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -fPIC -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -fPIC -O2 -Wall")
set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -fPIC -O0 -Wall -g -ggdb")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -fPIC -O2 -Wall")

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/common)
include_directories(${CMAKE_SOURCE_DIR}/src/common/exceptions)
include_directories(${CMAKE_SOURCE_DIR}/src/common/protocol)
include_directories(${CMAKE_SOURCE_DIR}/src/common/protocol/types)
include_directories(${CMAKE_SOURCE_DIR}/src/common/record)
include_directories(${CMAKE_SOURCE_DIR}/src/common/requests)
include_directories(${CMAKE_SOURCE_DIR}/src/common/resource)
include_directories(${CMAKE_SOURCE_DIR}/src/common/utils)

set(HEADER_FILE ${CMAKE_SOURCE_DIR}/include/kafkaclient-cpp.h)
aux_source_directory(./src SOURCE_FILE)

add_library(${OUTPUT_NAME}${D_SUFFIX} SHARED ${SOURCE_FILE})

install(TARGETS ${OUTPUT_NAME}${D_SUFFIX}
        LIBRARY DESTINATION lib)
install(FILES ${HEADER_FILE} DESTINATION include)
