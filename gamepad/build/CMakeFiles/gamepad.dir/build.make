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
CMAKE_SOURCE_DIR = /home/seame-workstation08/DES_Head-Unit/gamepad

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seame-workstation08/DES_Head-Unit/gamepad/build

# Include any dependencies generated for this target.
include CMakeFiles/gamepad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gamepad.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gamepad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gamepad.dir/flags.make

CMakeFiles/gamepad.dir/src/main.cpp.o: CMakeFiles/gamepad.dir/flags.make
CMakeFiles/gamepad.dir/src/main.cpp.o: /home/seame-workstation08/DES_Head-Unit/gamepad/src/main.cpp
CMakeFiles/gamepad.dir/src/main.cpp.o: CMakeFiles/gamepad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seame-workstation08/DES_Head-Unit/gamepad/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gamepad.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gamepad.dir/src/main.cpp.o -MF CMakeFiles/gamepad.dir/src/main.cpp.o.d -o CMakeFiles/gamepad.dir/src/main.cpp.o -c /home/seame-workstation08/DES_Head-Unit/gamepad/src/main.cpp

CMakeFiles/gamepad.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gamepad.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seame-workstation08/DES_Head-Unit/gamepad/src/main.cpp > CMakeFiles/gamepad.dir/src/main.cpp.i

CMakeFiles/gamepad.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gamepad.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seame-workstation08/DES_Head-Unit/gamepad/src/main.cpp -o CMakeFiles/gamepad.dir/src/main.cpp.s

CMakeFiles/gamepad.dir/src/gamepad.cpp.o: CMakeFiles/gamepad.dir/flags.make
CMakeFiles/gamepad.dir/src/gamepad.cpp.o: /home/seame-workstation08/DES_Head-Unit/gamepad/src/gamepad.cpp
CMakeFiles/gamepad.dir/src/gamepad.cpp.o: CMakeFiles/gamepad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seame-workstation08/DES_Head-Unit/gamepad/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gamepad.dir/src/gamepad.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gamepad.dir/src/gamepad.cpp.o -MF CMakeFiles/gamepad.dir/src/gamepad.cpp.o.d -o CMakeFiles/gamepad.dir/src/gamepad.cpp.o -c /home/seame-workstation08/DES_Head-Unit/gamepad/src/gamepad.cpp

CMakeFiles/gamepad.dir/src/gamepad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gamepad.dir/src/gamepad.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seame-workstation08/DES_Head-Unit/gamepad/src/gamepad.cpp > CMakeFiles/gamepad.dir/src/gamepad.cpp.i

CMakeFiles/gamepad.dir/src/gamepad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gamepad.dir/src/gamepad.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seame-workstation08/DES_Head-Unit/gamepad/src/gamepad.cpp -o CMakeFiles/gamepad.dir/src/gamepad.cpp.s

CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.o: CMakeFiles/gamepad.dir/flags.make
CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.o: /home/seame-workstation08/DES_Head-Unit/gamepad/src/gamepadsystem.cpp
CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.o: CMakeFiles/gamepad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seame-workstation08/DES_Head-Unit/gamepad/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.o -MF CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.o.d -o CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.o -c /home/seame-workstation08/DES_Head-Unit/gamepad/src/gamepadsystem.cpp

CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seame-workstation08/DES_Head-Unit/gamepad/src/gamepadsystem.cpp > CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.i

CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seame-workstation08/DES_Head-Unit/gamepad/src/gamepadsystem.cpp -o CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.s

CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.o: CMakeFiles/gamepad.dir/flags.make
CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.o: /home/seame-workstation08/DES_Head-Unit/gamepad/src/movingstubImpl.cpp
CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.o: CMakeFiles/gamepad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seame-workstation08/DES_Head-Unit/gamepad/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.o -MF CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.o.d -o CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.o -c /home/seame-workstation08/DES_Head-Unit/gamepad/src/movingstubImpl.cpp

CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seame-workstation08/DES_Head-Unit/gamepad/src/movingstubImpl.cpp > CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.i

CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seame-workstation08/DES_Head-Unit/gamepad/src/movingstubImpl.cpp -o CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.s

CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.o: CMakeFiles/gamepad.dir/flags.make
CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.o: /home/seame-workstation08/DES_Head-Unit/gamepad/src/lightstubImpl.cpp
CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.o: CMakeFiles/gamepad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seame-workstation08/DES_Head-Unit/gamepad/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.o -MF CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.o.d -o CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.o -c /home/seame-workstation08/DES_Head-Unit/gamepad/src/lightstubImpl.cpp

CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seame-workstation08/DES_Head-Unit/gamepad/src/lightstubImpl.cpp > CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.i

CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seame-workstation08/DES_Head-Unit/gamepad/src/lightstubImpl.cpp -o CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.s

# Object files for target gamepad
gamepad_OBJECTS = \
"CMakeFiles/gamepad.dir/src/main.cpp.o" \
"CMakeFiles/gamepad.dir/src/gamepad.cpp.o" \
"CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.o" \
"CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.o" \
"CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.o"

# External object files for target gamepad
gamepad_EXTERNAL_OBJECTS =

gamepad: CMakeFiles/gamepad.dir/src/main.cpp.o
gamepad: CMakeFiles/gamepad.dir/src/gamepad.cpp.o
gamepad: CMakeFiles/gamepad.dir/src/gamepadsystem.cpp.o
gamepad: CMakeFiles/gamepad.dir/src/movingstubImpl.cpp.o
gamepad: CMakeFiles/gamepad.dir/src/lightstubImpl.cpp.o
gamepad: CMakeFiles/gamepad.dir/build.make
gamepad: /home/seame-workstation08/build-commonapi/capicxx-core-runtime/build/libCommonAPI.so.3.2.0
gamepad: /usr/lib/x86_64-linux-gnu/libpython3.8.so
gamepad: CMakeFiles/gamepad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seame-workstation08/DES_Head-Unit/gamepad/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable gamepad"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gamepad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gamepad.dir/build: gamepad
.PHONY : CMakeFiles/gamepad.dir/build

CMakeFiles/gamepad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gamepad.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gamepad.dir/clean

CMakeFiles/gamepad.dir/depend:
	cd /home/seame-workstation08/DES_Head-Unit/gamepad/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seame-workstation08/DES_Head-Unit/gamepad /home/seame-workstation08/DES_Head-Unit/gamepad /home/seame-workstation08/DES_Head-Unit/gamepad/build /home/seame-workstation08/DES_Head-Unit/gamepad/build /home/seame-workstation08/DES_Head-Unit/gamepad/build/CMakeFiles/gamepad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gamepad.dir/depend

