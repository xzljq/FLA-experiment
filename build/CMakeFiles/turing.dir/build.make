# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ljq/Desktop/FLA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ljq/Desktop/FLA/build

# Include any dependencies generated for this target.
include CMakeFiles/turing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/turing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/turing.dir/flags.make

CMakeFiles/turing.dir/turing-project/main.cpp.o: CMakeFiles/turing.dir/flags.make
CMakeFiles/turing.dir/turing-project/main.cpp.o: ../turing-project/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljq/Desktop/FLA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/turing.dir/turing-project/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/turing.dir/turing-project/main.cpp.o -c /home/ljq/Desktop/FLA/turing-project/main.cpp

CMakeFiles/turing.dir/turing-project/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/turing.dir/turing-project/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljq/Desktop/FLA/turing-project/main.cpp > CMakeFiles/turing.dir/turing-project/main.cpp.i

CMakeFiles/turing.dir/turing-project/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/turing.dir/turing-project/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljq/Desktop/FLA/turing-project/main.cpp -o CMakeFiles/turing.dir/turing-project/main.cpp.s

CMakeFiles/turing.dir/turing-project/parser.cpp.o: CMakeFiles/turing.dir/flags.make
CMakeFiles/turing.dir/turing-project/parser.cpp.o: ../turing-project/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljq/Desktop/FLA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/turing.dir/turing-project/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/turing.dir/turing-project/parser.cpp.o -c /home/ljq/Desktop/FLA/turing-project/parser.cpp

CMakeFiles/turing.dir/turing-project/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/turing.dir/turing-project/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljq/Desktop/FLA/turing-project/parser.cpp > CMakeFiles/turing.dir/turing-project/parser.cpp.i

CMakeFiles/turing.dir/turing-project/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/turing.dir/turing-project/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljq/Desktop/FLA/turing-project/parser.cpp -o CMakeFiles/turing.dir/turing-project/parser.cpp.s

CMakeFiles/turing.dir/turing-project/simulator.cpp.o: CMakeFiles/turing.dir/flags.make
CMakeFiles/turing.dir/turing-project/simulator.cpp.o: ../turing-project/simulator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ljq/Desktop/FLA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/turing.dir/turing-project/simulator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/turing.dir/turing-project/simulator.cpp.o -c /home/ljq/Desktop/FLA/turing-project/simulator.cpp

CMakeFiles/turing.dir/turing-project/simulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/turing.dir/turing-project/simulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ljq/Desktop/FLA/turing-project/simulator.cpp > CMakeFiles/turing.dir/turing-project/simulator.cpp.i

CMakeFiles/turing.dir/turing-project/simulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/turing.dir/turing-project/simulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ljq/Desktop/FLA/turing-project/simulator.cpp -o CMakeFiles/turing.dir/turing-project/simulator.cpp.s

# Object files for target turing
turing_OBJECTS = \
"CMakeFiles/turing.dir/turing-project/main.cpp.o" \
"CMakeFiles/turing.dir/turing-project/parser.cpp.o" \
"CMakeFiles/turing.dir/turing-project/simulator.cpp.o"

# External object files for target turing
turing_EXTERNAL_OBJECTS =

../bin/turing: CMakeFiles/turing.dir/turing-project/main.cpp.o
../bin/turing: CMakeFiles/turing.dir/turing-project/parser.cpp.o
../bin/turing: CMakeFiles/turing.dir/turing-project/simulator.cpp.o
../bin/turing: CMakeFiles/turing.dir/build.make
../bin/turing: CMakeFiles/turing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ljq/Desktop/FLA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/turing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/turing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/turing.dir/build: ../bin/turing

.PHONY : CMakeFiles/turing.dir/build

CMakeFiles/turing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/turing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/turing.dir/clean

CMakeFiles/turing.dir/depend:
	cd /home/ljq/Desktop/FLA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljq/Desktop/FLA /home/ljq/Desktop/FLA /home/ljq/Desktop/FLA/build /home/ljq/Desktop/FLA/build /home/ljq/Desktop/FLA/build/CMakeFiles/turing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/turing.dir/depend

