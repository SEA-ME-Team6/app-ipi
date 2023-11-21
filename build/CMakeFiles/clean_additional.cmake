# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "head_unit/CMakeFiles/head_unit_autogen.dir/AutogenUsed.txt"
  "head_unit/CMakeFiles/head_unit_autogen.dir/ParseCache.txt"
  "head_unit/head_unit_autogen"
  "instrument_cluster/CMakeFiles/instrument_cluster_autogen.dir/AutogenUsed.txt"
  "instrument_cluster/CMakeFiles/instrument_cluster_autogen.dir/ParseCache.txt"
  "instrument_cluster/instrument_cluster_autogen"
  )
endif()
