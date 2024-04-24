# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\VehicleHealthMonitorSystem_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\VehicleHealthMonitorSystem_autogen.dir\\ParseCache.txt"
  "Models\\CMakeFiles\\Models_autogen.dir\\AutogenUsed.txt"
  "Models\\CMakeFiles\\Models_autogen.dir\\ParseCache.txt"
  "Models\\Models_autogen"
  "VehicleHealthMonitorSystem_autogen"
  )
endif()
