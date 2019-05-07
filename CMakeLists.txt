cmake_minimum_required(VERSION 3.12)
project(lab12)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

add_executable(lab12 main.cpp Game.h JumpItGame.cpp JumpItGame.h)
add_custom_command(TARGET lab12 PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/lab12.txt ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
