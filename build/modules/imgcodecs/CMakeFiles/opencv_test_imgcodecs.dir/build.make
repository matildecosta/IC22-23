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
CMAKE_SOURCE_DIR = /home/matilde/Desktop/IC/IC-Lab/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matilde/Desktop/IC/IC-Lab/build

# Include any dependencies generated for this target.
include modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/compiler_depend.make

# Include the progress variables for this target.
include modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/progress.make

# Include the compile flags for this target's objects.
include modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.o: /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_common.cpp
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/IC-Lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.o"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.o -MF CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.o.d -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.o -c /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_common.cpp

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.i"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_common.cpp > CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.i

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.s"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_common.cpp -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.s

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o: /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_grfmt.cpp
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/IC-Lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o -MF CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o.d -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o -c /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_grfmt.cpp

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.i"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_grfmt.cpp > CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.i

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.s"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_grfmt.cpp -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.s

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.o: /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_jpeg.cpp
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/IC-Lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.o"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.o -MF CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.o.d -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.o -c /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_jpeg.cpp

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.i"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_jpeg.cpp > CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.i

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.s"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_jpeg.cpp -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.s

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o: /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_main.cpp
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/IC-Lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o -MF CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o.d -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o -c /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_main.cpp

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.i"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_main.cpp > CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.i

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.s"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_main.cpp -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.s

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.o: /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_png.cpp
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/IC-Lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.o"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.o -MF CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.o.d -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.o -c /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_png.cpp

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.i"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_png.cpp > CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.i

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.s"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_png.cpp -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.s

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.o: /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_read_write.cpp
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/IC-Lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.o"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.o -MF CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.o.d -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.o -c /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_read_write.cpp

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.i"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_read_write.cpp > CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.i

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.s"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_read_write.cpp -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.s

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.o: /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_tiff.cpp
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/IC-Lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.o"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.o -MF CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.o.d -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.o -c /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_tiff.cpp

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.i"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_tiff.cpp > CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.i

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.s"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_tiff.cpp -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.s

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.o: /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_webp.cpp
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.o: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matilde/Desktop/IC/IC-Lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.o"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.o -MF CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.o.d -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.o -c /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_webp.cpp

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.i"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_webp.cpp > CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.i

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.s"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs/test/test_webp.cpp -o CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.s

# Object files for target opencv_test_imgcodecs
opencv_test_imgcodecs_OBJECTS = \
"CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.o" \
"CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o" \
"CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.o" \
"CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o" \
"CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.o" \
"CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.o" \
"CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.o" \
"CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.o"

# External object files for target opencv_test_imgcodecs
opencv_test_imgcodecs_EXTERNAL_OBJECTS =

bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_common.cpp.o
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_grfmt.cpp.o
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_jpeg.cpp.o
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_main.cpp.o
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_png.cpp.o
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_read_write.cpp.o
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_tiff.cpp.o
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/test/test_webp.cpp.o
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/build.make
bin/opencv_test_imgcodecs: lib/libopencv_ts.a
bin/opencv_test_imgcodecs: lib/libopencv_highgui.so.4.6.0
bin/opencv_test_imgcodecs: 3rdparty/lib/libippiw.a
bin/opencv_test_imgcodecs: 3rdparty/ippicv/ippicv_lnx/icv/lib/intel64/libippicv.a
bin/opencv_test_imgcodecs: lib/libopencv_videoio.so.4.6.0
bin/opencv_test_imgcodecs: lib/libopencv_imgcodecs.so.4.6.0
bin/opencv_test_imgcodecs: lib/libopencv_imgproc.so.4.6.0
bin/opencv_test_imgcodecs: lib/libopencv_core.so.4.6.0
bin/opencv_test_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matilde/Desktop/IC/IC-Lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ../../bin/opencv_test_imgcodecs"
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_test_imgcodecs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/build: bin/opencv_test_imgcodecs
.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/build

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/clean:
	cd /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs && $(CMAKE_COMMAND) -P CMakeFiles/opencv_test_imgcodecs.dir/cmake_clean.cmake
.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/clean

modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/depend:
	cd /home/matilde/Desktop/IC/IC-Lab/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matilde/Desktop/IC/IC-Lab/opencv /home/matilde/Desktop/IC/IC-Lab/opencv/modules/imgcodecs /home/matilde/Desktop/IC/IC-Lab/build /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs /home/matilde/Desktop/IC/IC-Lab/build/modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/imgcodecs/CMakeFiles/opencv_test_imgcodecs.dir/depend

