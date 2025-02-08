cmake_minimum_required (VERSION 3.14)

project("Momentum")

# Define C++ properties.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable testing for current directory and below.
enable_testing()

# Include sub-projects.
add_subdirectory("src")
add_subdirectory("tests")
