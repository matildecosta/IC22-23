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
CMAKE_SOURCE_DIR = /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3/build

# Include any dependencies generated for this target.
include CMakeFiles/Compress.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Compress.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Compress.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Compress.dir/flags.make

CMakeFiles/Compress.dir/Compress.cpp.o: CMakeFiles/Compress.dir/flags.make
CMakeFiles/Compress.dir/Compress.cpp.o: ../Compress.cpp
CMakeFiles/Compress.dir/Compress.cpp.o: CMakeFiles/Compress.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Compress.dir/Compress.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Compress.dir/Compress.cpp.o -MF CMakeFiles/Compress.dir/Compress.cpp.o.d -o CMakeFiles/Compress.dir/Compress.cpp.o -c /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3/Compress.cpp

CMakeFiles/Compress.dir/Compress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compress.dir/Compress.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3/Compress.cpp > CMakeFiles/Compress.dir/Compress.cpp.i

CMakeFiles/Compress.dir/Compress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compress.dir/Compress.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3/Compress.cpp -o CMakeFiles/Compress.dir/Compress.cpp.s

# Object files for target Compress
Compress_OBJECTS = \
"CMakeFiles/Compress.dir/Compress.cpp.o"

# External object files for target Compress
Compress_EXTERNAL_OBJECTS =

../compress_text/Compress: CMakeFiles/Compress.dir/Compress.cpp.o
../compress_text/Compress: CMakeFiles/Compress.dir/build.make
../compress_text/Compress: CMakeFiles/Compress.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../compress_text/Compress"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Compress.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Compress.dir/build: ../compress_text/Compress
.PHONY : CMakeFiles/Compress.dir/build

CMakeFiles/Compress.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Compress.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Compress.dir/clean

CMakeFiles/Compress.dir/depend:
	cd /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3 /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3 /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3/build /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3/build /home/saldanha/Desktop/MECT/Projetos/IC/IC22-23/Lab3/build/CMakeFiles/Compress.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Compress.dir/depend

