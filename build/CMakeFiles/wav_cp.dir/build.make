# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matilde/Desktop/IC/Lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matilde/Desktop/IC/Lab1/build

# Include any dependencies generated for this target.
include CMakeFiles/wav_cp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/wav_cp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/wav_cp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wav_cp.dir/flags.make

CMakeFiles/wav_cp.dir/wav_cp.cpp.o: CMakeFiles/wav_cp.dir/flags.make
CMakeFiles/wav_cp.dir/wav_cp.cpp.o: ../wav_cp.cpp
CMakeFiles/wav_cp.dir/wav_cp.cpp.o: CMakeFiles/wav_cp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/Lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wav_cp.dir/wav_cp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wav_cp.dir/wav_cp.cpp.o -MF CMakeFiles/wav_cp.dir/wav_cp.cpp.o.d -o CMakeFiles/wav_cp.dir/wav_cp.cpp.o -c /home/matilde/Desktop/IC/Lab1/wav_cp.cpp

CMakeFiles/wav_cp.dir/wav_cp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wav_cp.dir/wav_cp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/Lab1/wav_cp.cpp > CMakeFiles/wav_cp.dir/wav_cp.cpp.i

CMakeFiles/wav_cp.dir/wav_cp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wav_cp.dir/wav_cp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/Lab1/wav_cp.cpp -o CMakeFiles/wav_cp.dir/wav_cp.cpp.s

# Object files for target wav_cp
wav_cp_OBJECTS = \
"CMakeFiles/wav_cp.dir/wav_cp.cpp.o"

# External object files for target wav_cp
wav_cp_EXTERNAL_OBJECTS =

/home/matilde/Desktop/IC/sndfile-example-bin/wav_cp: CMakeFiles/wav_cp.dir/wav_cp.cpp.o
/home/matilde/Desktop/IC/sndfile-example-bin/wav_cp: CMakeFiles/wav_cp.dir/build.make
/home/matilde/Desktop/IC/sndfile-example-bin/wav_cp: CMakeFiles/wav_cp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matilde/Desktop/IC/Lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/matilde/Desktop/IC/sndfile-example-bin/wav_cp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wav_cp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wav_cp.dir/build: /home/matilde/Desktop/IC/sndfile-example-bin/wav_cp
.PHONY : CMakeFiles/wav_cp.dir/build

CMakeFiles/wav_cp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wav_cp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wav_cp.dir/clean

CMakeFiles/wav_cp.dir/depend:
	cd /home/matilde/Desktop/IC/Lab1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matilde/Desktop/IC/Lab1 /home/matilde/Desktop/IC/Lab1 /home/matilde/Desktop/IC/Lab1/build /home/matilde/Desktop/IC/Lab1/build /home/matilde/Desktop/IC/Lab1/build/CMakeFiles/wav_cp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wav_cp.dir/depend

