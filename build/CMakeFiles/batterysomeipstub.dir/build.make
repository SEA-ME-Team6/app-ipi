# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/seame-workstation08/DES_Head-Unit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seame-workstation08/DES_Head-Unit/build

# Include any dependencies generated for this target.
include CMakeFiles/batterysomeipstub.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/batterysomeipstub.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/batterysomeipstub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/batterysomeipstub.dir/flags.make

CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.o: CMakeFiles/batterysomeipstub.dir/flags.make
CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.o: /home/seame-workstation08/DES_Head-Unit/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp
CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.o: CMakeFiles/batterysomeipstub.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seame-workstation08/DES_Head-Unit/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.o -MF CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.o.d -o CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.o -c /home/seame-workstation08/DES_Head-Unit/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp

CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seame-workstation08/DES_Head-Unit/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp > CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.i

CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seame-workstation08/DES_Head-Unit/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp -o CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.s

# Object files for target batterysomeipstub
batterysomeipstub_OBJECTS = \
"CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.o"

# External object files for target batterysomeipstub
batterysomeipstub_EXTERNAL_OBJECTS =

libbatterysomeipstub.so: CMakeFiles/batterysomeipstub.dir/src-gen/battery/someip/stub/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp.o
libbatterysomeipstub.so: CMakeFiles/batterysomeipstub.dir/build.make
libbatterysomeipstub.so: /home/seame-workstation08/build-commonapi/capicxx-someip-runtime/build/libCommonAPI-SomeIP.so.3.2.0
libbatterysomeipstub.so: /usr/local/lib/libvsomeip3.so.3.1.20
libbatterysomeipstub.so: /home/seame-workstation08/build-commonapi/capicxx-core-runtime/build/libCommonAPI.so.3.2.0
libbatterysomeipstub.so: CMakeFiles/batterysomeipstub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seame-workstation08/DES_Head-Unit/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libbatterysomeipstub.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/batterysomeipstub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/batterysomeipstub.dir/build: libbatterysomeipstub.so
.PHONY : CMakeFiles/batterysomeipstub.dir/build

CMakeFiles/batterysomeipstub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/batterysomeipstub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/batterysomeipstub.dir/clean

CMakeFiles/batterysomeipstub.dir/depend:
	cd /home/seame-workstation08/DES_Head-Unit/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seame-workstation08/DES_Head-Unit /home/seame-workstation08/DES_Head-Unit /home/seame-workstation08/DES_Head-Unit/build /home/seame-workstation08/DES_Head-Unit/build /home/seame-workstation08/DES_Head-Unit/build/CMakeFiles/batterysomeipstub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/batterysomeipstub.dir/depend

