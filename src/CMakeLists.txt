cmake_minimum_required (VERSION 3.14)

project ("Momentum.Library")

# Define C++ properties.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# Momentum Library
#

# Create an interface library.
add_library (${PROJECT_NAME} INTERFACE)

# Include the current directory as an interface include directory.
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
