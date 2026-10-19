cmake_minimum_required(VERSION 3.20)
project(ExplicitClientApp LANGUAGES CXX)

add_executable(ExplicitClientApp main.cpp)

add_custom_command(TARGET ExplicitClientApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_SOURCE_DIR}/bin/LinearSolver.dll"
    "$<TARGET_FILE_DIR:ExplicitClientApp>"
)