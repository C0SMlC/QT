# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Form_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Form_autogen.dir\\ParseCache.txt"
  "Form_autogen"
  )
endif()
