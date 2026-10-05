cmake_minimum_required(VERSION 3.20)
project(Geometric_figures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(out
    main.cpp
    classes_cpp/Shape.cpp
    classes_cpp/Circle.cpp
    classes_cpp/Rectangular.cpp     # ← с большой R
    classes_cpp/Square.cpp
    classes_cpp/Triangl.cpp
)

target_include_directories(out PRIVATE include_h)