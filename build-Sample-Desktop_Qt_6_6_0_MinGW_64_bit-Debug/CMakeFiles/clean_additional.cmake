# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Sample_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Sample_autogen.dir\\ParseCache.txt"
  "Sample_autogen"
  )
endif()
