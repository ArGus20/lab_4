cmake_minimum_required(VERSION 3.20)
project(ImplicitClientApp LANGUAGES CXX)

add_executable(ImplicitClientApp main.cpp)

target_include_directories(ImplicitClientApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ImplicitClientApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/LinearSolver.lib
)

add_custom_command(TARGET ImplicitClientApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_SOURCE_DIR}/bin/LinearSolver.dll"
    "$<TARGET_FILE_DIR:ImplicitClientApp>"
)
