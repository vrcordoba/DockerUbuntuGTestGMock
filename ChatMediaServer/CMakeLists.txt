
cmake_minimum_required(VERSION 2.8.11)
project(ChatMediaServerTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(/usr/include/gmock)

add_executable(ChatMediaServerTest
   Chat.h
   Chat.cpp
   UserMock.h
   User.h
   MediaServer.h
   MediaServerMock.h
   NotEnoughResourcesException.h
   ChatMediaServerTest.cpp)
target_link_libraries(ChatMediaServerTest ${GTEST_LIBRARIES} pthread gmock_main gmock)

