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
CMAKE_SOURCE_DIR = /home/matilde/Desktop/IC/IC-Lab/Lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matilde/Desktop/IC/IC-Lab/Lab2/build

# Include any dependencies generated for this target.
include CMakeFiles/ex2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ex2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ex2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex2.dir/flags.make

CMakeFiles/ex2.dir/ex2.cpp.o: CMakeFiles/ex2.dir/flags.make
CMakeFiles/ex2.dir/ex2.cpp.o: ../ex2.cpp
CMakeFiles/ex2.dir/ex2.cpp.o: CMakeFiles/ex2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/IC-Lab/Lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex2.dir/ex2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ex2.dir/ex2.cpp.o -MF CMakeFiles/ex2.dir/ex2.cpp.o.d -o CMakeFiles/ex2.dir/ex2.cpp.o -c /home/matilde/Desktop/IC/IC-Lab/Lab2/ex2.cpp

CMakeFiles/ex2.dir/ex2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.dir/ex2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/IC-Lab/Lab2/ex2.cpp > CMakeFiles/ex2.dir/ex2.cpp.i

CMakeFiles/ex2.dir/ex2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.dir/ex2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/IC-Lab/Lab2/ex2.cpp -o CMakeFiles/ex2.dir/ex2.cpp.s

# Object files for target ex2
ex2_OBJECTS = \
"CMakeFiles/ex2.dir/ex2.cpp.o"

# External object files for target ex2
ex2_EXTERNAL_OBJECTS =

../opencv-example-bin/ex2: CMakeFiles/ex2.dir/ex2.cpp.o
../opencv-example-bin/ex2: CMakeFiles/ex2.dir/build.make
../opencv-example-bin/ex2: /usr/local/lib/libopencv_gapi.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_highgui.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_ml.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_objdetect.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_photo.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_stitching.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_video.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_videoio.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_dnn.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_calib3d.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_features2d.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_flann.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_imgproc.so.4.6.0
../opencv-example-bin/ex2: /usr/local/lib/libopencv_core.so.4.6.0
../opencv-example-bin/ex2: CMakeFiles/ex2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matilde/Desktop/IC/IC-Lab/Lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../opencv-example-bin/ex2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex2.dir/build: ../opencv-example-bin/ex2
.PHONY : CMakeFiles/ex2.dir/build

CMakeFiles/ex2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex2.dir/clean

CMakeFiles/ex2.dir/depend:
	cd /home/matilde/Desktop/IC/IC-Lab/Lab2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matilde/Desktop/IC/IC-Lab/Lab2 /home/matilde/Desktop/IC/IC-Lab/Lab2 /home/matilde/Desktop/IC/IC-Lab/Lab2/build /home/matilde/Desktop/IC/IC-Lab/Lab2/build /home/matilde/Desktop/IC/IC-Lab/Lab2/build/CMakeFiles/ex2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex2.dir/depend

