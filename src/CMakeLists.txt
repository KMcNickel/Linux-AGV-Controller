cmake_minimum_required(VERSION 3.12)

project(agv_controller C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


add_executable(${PROJECT_NAME}
    main.cpp
)