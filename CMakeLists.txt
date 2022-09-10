cmake_minimum_required(VERSION 3.12)

project(agv_controller C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/spdlog/build)
set(SPDLOG_ROOT ${CMAKE_SOURCE_DIR}/spdlog/build/CMakeFiles/Export/lib/cmake/spdlog)

find_package(spdlog REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/spdlog/include")

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    spdlog
)