# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Assignment-II_autogen"
  "CMakeFiles\\Assignment-II_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Assignment-II_autogen.dir\\ParseCache.txt"
  )
endif()
