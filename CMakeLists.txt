cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -pedantic -pthread -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcurl -lcurlpp")

set(PROJECT_NAME "app")

project(${PROJECT_NAME})

set(sources
main.cc
)

find_package(SFML REQUIRED system graphics window network audio)

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} curlpp)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})