cmake_minimum_required(VERSION 3.12)

project(agv_controller C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

find_package(spdlog REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/socketcan.cpp
    src/battery_manager_interface.cpp
)

target_link_libraries(${PROJECT_NAME}
    spdlog
)