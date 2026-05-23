# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Point_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Point_autogen.dir\\ParseCache.txt"
  "Point_autogen"
  )
endif()
