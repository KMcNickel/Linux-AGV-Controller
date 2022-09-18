cmake_minimum_required(VERSION 3.12)

project(agv_controller C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

find_package(spdlog REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/socketcan.cpp
    src/battery_manager_interface.cpp
    src/mqtt_transfer.cpp
    src/odrive_interface.cpp
)

add_custom_command(
    TARGET ${PROJECT_NAME}
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND}
        -DHEADER_DIR:PATH="${CMAKE_SOURCE_DIR}"
        -P "${CMAKE_SOURCE_DIR}/set_build_number.cmake"
)

target_link_libraries(${PROJECT_NAME}
    spdlog
    mosquitto
)