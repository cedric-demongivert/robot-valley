cmake_minimum_required (VERSION 2.6)

project(robot-valley)

include_directories(./header)
include_directories(./src)
include_directories(./libs)

link_directories(${PROJECT_SOURCE_DIR}/libs)

file(GLOB_RECURSE source_files ./src/*.cpp)
file(GLOB_RECURSE header_files ./header/*.hpp)
file(GLOB_RECURSE template_files ./header/*.hxx)

file(GLOB_RECURSE test_files ./tests/*.cpp)

add_executable(
  robot-valley
  ${source_files}
  ${header_files}
  ${template_files}
)

add_executable(
  robot-valley-tests
  ${source_files}
  ${header_files}
  ${template_files}
  ${test_files}
)

set_property(TARGET robot-valley PROPERTY CXX_STANDARD 14)
set_property(TARGET robot-valley PROPERTY CXX_STANDARD_REQUIRED ON)

set_property(TARGET robot-valley-tests PROPERTY CXX_STANDARD 14)
set_property(TARGET robot-valley-tests PROPERTY CXX_STANDARD_REQUIRED ON)
