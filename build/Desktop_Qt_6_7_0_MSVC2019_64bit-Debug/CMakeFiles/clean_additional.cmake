# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appRead_Data_Mock_Project_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appRead_Data_Mock_Project_autogen.dir\\ParseCache.txt"
  "appRead_Data_Mock_Project_autogen"
  )
endif()
