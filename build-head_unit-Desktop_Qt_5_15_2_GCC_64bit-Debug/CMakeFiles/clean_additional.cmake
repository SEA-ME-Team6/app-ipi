# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/head_unit_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/head_unit_autogen.dir/ParseCache.txt"
  "CMakeFiles/hu-gearsomeipproxy_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/hu-gearsomeipproxy_autogen.dir/ParseCache.txt"
  "CMakeFiles/hu-lightsomeipproxy_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/hu-lightsomeipproxy_autogen.dir/ParseCache.txt"
  "CMakeFiles/hu-speedsomeipproxy_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/hu-speedsomeipproxy_autogen.dir/ParseCache.txt"
  "head_unit_autogen"
  "hu-gearsomeipproxy_autogen"
  "hu-lightsomeipproxy_autogen"
  "hu-speedsomeipproxy_autogen"
  )
endif()
