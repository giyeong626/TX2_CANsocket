# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can/build

# Include any dependencies generated for this target.
include CMakeFiles/MotorDriverTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MotorDriverTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MotorDriverTest.dir/flags.make

CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o: CMakeFiles/MotorDriverTest.dir/flags.make
CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o: ../src/MotorDriverTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o -c /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can/src/MotorDriverTest.cpp

CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can/src/MotorDriverTest.cpp > CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.i

CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can/src/MotorDriverTest.cpp -o CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.s

CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o.requires:

.PHONY : CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o.requires

CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o.provides: CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o.requires
	$(MAKE) -f CMakeFiles/MotorDriverTest.dir/build.make CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o.provides.build
.PHONY : CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o.provides

CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o.provides.build: CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o


# Object files for target MotorDriverTest
MotorDriverTest_OBJECTS = \
"CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o"

# External object files for target MotorDriverTest
MotorDriverTest_EXTERNAL_OBJECTS =

MotorDriverTest: CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o
MotorDriverTest: CMakeFiles/MotorDriverTest.dir/build.make
MotorDriverTest: libmini_cheetah_motor_driver-static.a
MotorDriverTest: CMakeFiles/MotorDriverTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MotorDriverTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MotorDriverTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MotorDriverTest.dir/build: MotorDriverTest

.PHONY : CMakeFiles/MotorDriverTest.dir/build

CMakeFiles/MotorDriverTest.dir/requires: CMakeFiles/MotorDriverTest.dir/src/MotorDriverTest.cpp.o.requires

.PHONY : CMakeFiles/MotorDriverTest.dir/requires

CMakeFiles/MotorDriverTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MotorDriverTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MotorDriverTest.dir/clean

CMakeFiles/MotorDriverTest.dir/depend:
	cd /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can/build /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can/build /home/speartech-dev/TX2_CANsocket/mini-cheetah-tmotor-can/build/CMakeFiles/MotorDriverTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MotorDriverTest.dir/depend

