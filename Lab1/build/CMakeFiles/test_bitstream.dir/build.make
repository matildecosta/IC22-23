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
CMAKE_SOURCE_DIR = /home/matilde/Desktop/IC/IC-Lab/Lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matilde/Desktop/IC/IC-Lab/Lab1/build

# Include any dependencies generated for this target.
include CMakeFiles/test_bitstream.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_bitstream.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_bitstream.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_bitstream.dir/flags.make

CMakeFiles/test_bitstream.dir/test_bs.cpp.o: CMakeFiles/test_bitstream.dir/flags.make
CMakeFiles/test_bitstream.dir/test_bs.cpp.o: ../test_bs.cpp
CMakeFiles/test_bitstream.dir/test_bs.cpp.o: CMakeFiles/test_bitstream.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/IC-Lab/Lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_bitstream.dir/test_bs.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_bitstream.dir/test_bs.cpp.o -MF CMakeFiles/test_bitstream.dir/test_bs.cpp.o.d -o CMakeFiles/test_bitstream.dir/test_bs.cpp.o -c /home/matilde/Desktop/IC/IC-Lab/Lab1/test_bs.cpp

CMakeFiles/test_bitstream.dir/test_bs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_bitstream.dir/test_bs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/IC-Lab/Lab1/test_bs.cpp > CMakeFiles/test_bitstream.dir/test_bs.cpp.i

CMakeFiles/test_bitstream.dir/test_bs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_bitstream.dir/test_bs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/IC-Lab/Lab1/test_bs.cpp -o CMakeFiles/test_bitstream.dir/test_bs.cpp.s

# Object files for target test_bitstream
test_bitstream_OBJECTS = \
"CMakeFiles/test_bitstream.dir/test_bs.cpp.o"

# External object files for target test_bitstream
test_bitstream_EXTERNAL_OBJECTS =

/home/matilde/Desktop/IC/IC-Lab/sndfile-example-bin/test_bitstream: CMakeFiles/test_bitstream.dir/test_bs.cpp.o
/home/matilde/Desktop/IC/IC-Lab/sndfile-example-bin/test_bitstream: CMakeFiles/test_bitstream.dir/build.make
/home/matilde/Desktop/IC/IC-Lab/sndfile-example-bin/test_bitstream: CMakeFiles/test_bitstream.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matilde/Desktop/IC/IC-Lab/Lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/matilde/Desktop/IC/IC-Lab/sndfile-example-bin/test_bitstream"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_bitstream.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_bitstream.dir/build: /home/matilde/Desktop/IC/IC-Lab/sndfile-example-bin/test_bitstream
.PHONY : CMakeFiles/test_bitstream.dir/build

CMakeFiles/test_bitstream.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_bitstream.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_bitstream.dir/clean

CMakeFiles/test_bitstream.dir/depend:
	cd /home/matilde/Desktop/IC/IC-Lab/Lab1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matilde/Desktop/IC/IC-Lab/Lab1 /home/matilde/Desktop/IC/IC-Lab/Lab1 /home/matilde/Desktop/IC/IC-Lab/Lab1/build /home/matilde/Desktop/IC/IC-Lab/Lab1/build /home/matilde/Desktop/IC/IC-Lab/Lab1/build/CMakeFiles/test_bitstream.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_bitstream.dir/depend

