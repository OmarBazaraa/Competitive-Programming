cmake_minimum_required (VERSION 3.14)

project ("Momentum.Tests")

# Define C++ properties.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# GoogleTest
#

include(FetchContent)

# Declare how to fetch GoogleTest.
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.16.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Fetch GoogleTest.
FetchContent_MakeAvailable(googletest)

#
# Momentum Tests
#

# Reference all `.h` & `.cpp` files in the library.
file(GLOB_RECURSE TEST_FILES "*.h" "*.cpp")

# Create a test executable.
add_executable(${PROJECT_NAME} ${TEST_FILES})

# Link test executable against Momentum.Library.
target_link_libraries(${PROJECT_NAME} Momentum.Library)

#
# GoogleTest Integration
#

include(GoogleTest)

# Link test executable against GoogleTest.
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

# Make tests discoverable by CTest.
gtest_discover_tests(${PROJECT_NAME})
