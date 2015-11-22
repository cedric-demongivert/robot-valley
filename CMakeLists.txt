CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Project & project configuration
PROJECT(robot-valley)

#LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/SDL2)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/SDL2)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

# Macro for listing subdirs 
# See http://stackoverflow.com/questions/7787823/cmake-how-to-get-the-name-of-all-subdirectories-of-a-directory
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

# Subdirectories
ADD_SUBDIRECTORY(robot-valley)
ADD_SUBDIRECTORY(robot-valley-tests)
