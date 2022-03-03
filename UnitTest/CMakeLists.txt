cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

set(SRC_LIST main.cpp ../Utils/Utils.cpp ../CFrequencyDictionary.cpp)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests ${SRC_LIST})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
