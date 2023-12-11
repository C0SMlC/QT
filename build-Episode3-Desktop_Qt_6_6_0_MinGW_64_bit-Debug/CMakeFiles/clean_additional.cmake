# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Episode3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Episode3_autogen.dir\\ParseCache.txt"
  "Episode3_autogen"
  )
endif()
