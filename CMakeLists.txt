set(PROJECT_NAME Eth2CAN)
project(${PROJECT_NAME})

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


include_directories(
        ${PROJECT_SOURCE_DIR}/inc
)

add_executable(${PROJECT_NAME} main.cc src/CanComm.cc)

target_link_libraries(${PROJECT_NAME} pthread)
