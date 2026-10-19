cmake_minimum_required(VERSION 3.20)
project(MatrixOps LANGUAGES CXX)

add_library(MatrixOps SHARED src/MatrixOps.cpp)

target_compile_definitions(MatrixOps PRIVATE MATRIXOPS_EXPORTS)

target_include_directories(MatrixOps PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(MatrixOps PUBLIC cxx_std_20)
