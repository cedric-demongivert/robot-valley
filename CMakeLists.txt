cmake_minimum_required (VERSION 2.6)

file(GLOB_RECURSE source_files ./src/*.cpp)
file(GLOB_RECURSE header_files ./header/*.hpp)
file(GLOB_RECURSE template_files ./header/*.hxx)

add_executable(
  robot-valley.exe
  ${source_files}
  ${header_files} 
  ${template_files}
)
