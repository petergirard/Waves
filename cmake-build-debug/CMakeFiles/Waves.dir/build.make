# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /mnt/c/Users/Peter/Repos/Waves

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Peter/Repos/Waves/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Waves.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Waves.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Waves.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Waves.dir/flags.make

CMakeFiles/Waves.dir/main.cpp.o: CMakeFiles/Waves.dir/flags.make
CMakeFiles/Waves.dir/main.cpp.o: /mnt/c/Users/Peter/Repos/Waves/main.cpp
CMakeFiles/Waves.dir/main.cpp.o: CMakeFiles/Waves.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Waves.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Waves.dir/main.cpp.o -MF CMakeFiles/Waves.dir/main.cpp.o.d -o CMakeFiles/Waves.dir/main.cpp.o -c /mnt/c/Users/Peter/Repos/Waves/main.cpp

CMakeFiles/Waves.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Waves.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Peter/Repos/Waves/main.cpp > CMakeFiles/Waves.dir/main.cpp.i

CMakeFiles/Waves.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Waves.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Peter/Repos/Waves/main.cpp -o CMakeFiles/Waves.dir/main.cpp.s

CMakeFiles/Waves.dir/src/Sim/Physics.cpp.o: CMakeFiles/Waves.dir/flags.make
CMakeFiles/Waves.dir/src/Sim/Physics.cpp.o: /mnt/c/Users/Peter/Repos/Waves/src/Sim/Physics.cpp
CMakeFiles/Waves.dir/src/Sim/Physics.cpp.o: CMakeFiles/Waves.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Waves.dir/src/Sim/Physics.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Waves.dir/src/Sim/Physics.cpp.o -MF CMakeFiles/Waves.dir/src/Sim/Physics.cpp.o.d -o CMakeFiles/Waves.dir/src/Sim/Physics.cpp.o -c /mnt/c/Users/Peter/Repos/Waves/src/Sim/Physics.cpp

CMakeFiles/Waves.dir/src/Sim/Physics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Waves.dir/src/Sim/Physics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Peter/Repos/Waves/src/Sim/Physics.cpp > CMakeFiles/Waves.dir/src/Sim/Physics.cpp.i

CMakeFiles/Waves.dir/src/Sim/Physics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Waves.dir/src/Sim/Physics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Peter/Repos/Waves/src/Sim/Physics.cpp -o CMakeFiles/Waves.dir/src/Sim/Physics.cpp.s

CMakeFiles/Waves.dir/src/Sim/Display.cpp.o: CMakeFiles/Waves.dir/flags.make
CMakeFiles/Waves.dir/src/Sim/Display.cpp.o: /mnt/c/Users/Peter/Repos/Waves/src/Sim/Display.cpp
CMakeFiles/Waves.dir/src/Sim/Display.cpp.o: CMakeFiles/Waves.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Waves.dir/src/Sim/Display.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Waves.dir/src/Sim/Display.cpp.o -MF CMakeFiles/Waves.dir/src/Sim/Display.cpp.o.d -o CMakeFiles/Waves.dir/src/Sim/Display.cpp.o -c /mnt/c/Users/Peter/Repos/Waves/src/Sim/Display.cpp

CMakeFiles/Waves.dir/src/Sim/Display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Waves.dir/src/Sim/Display.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Peter/Repos/Waves/src/Sim/Display.cpp > CMakeFiles/Waves.dir/src/Sim/Display.cpp.i

CMakeFiles/Waves.dir/src/Sim/Display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Waves.dir/src/Sim/Display.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Peter/Repos/Waves/src/Sim/Display.cpp -o CMakeFiles/Waves.dir/src/Sim/Display.cpp.s

CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.o: CMakeFiles/Waves.dir/flags.make
CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.o: /mnt/c/Users/Peter/Repos/Waves/src/Util/UnitConversion.cpp
CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.o: CMakeFiles/Waves.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.o -MF CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.o.d -o CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.o -c /mnt/c/Users/Peter/Repos/Waves/src/Util/UnitConversion.cpp

CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Peter/Repos/Waves/src/Util/UnitConversion.cpp > CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.i

CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Peter/Repos/Waves/src/Util/UnitConversion.cpp -o CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.s

CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.o: CMakeFiles/Waves.dir/flags.make
CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.o: /mnt/c/Users/Peter/Repos/Waves/src/Util/MathUtils.cpp
CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.o: CMakeFiles/Waves.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.o -MF CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.o.d -o CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.o -c /mnt/c/Users/Peter/Repos/Waves/src/Util/MathUtils.cpp

CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Peter/Repos/Waves/src/Util/MathUtils.cpp > CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.i

CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Peter/Repos/Waves/src/Util/MathUtils.cpp -o CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.s

CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.o: CMakeFiles/Waves.dir/flags.make
CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.o: /mnt/c/Users/Peter/Repos/Waves/src/Util/FrameTransformations.cpp
CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.o: CMakeFiles/Waves.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.o -MF CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.o.d -o CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.o -c /mnt/c/Users/Peter/Repos/Waves/src/Util/FrameTransformations.cpp

CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Peter/Repos/Waves/src/Util/FrameTransformations.cpp > CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.i

CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Peter/Repos/Waves/src/Util/FrameTransformations.cpp -o CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.s

CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.o: CMakeFiles/Waves.dir/flags.make
CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.o: /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Maneuver/ManeuverController.cpp
CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.o: CMakeFiles/Waves.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.o -MF CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.o.d -o CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.o -c /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Maneuver/ManeuverController.cpp

CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Maneuver/ManeuverController.cpp > CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.i

CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Maneuver/ManeuverController.cpp -o CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.s

CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.o: CMakeFiles/Waves.dir/flags.make
CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.o: /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Maneuver/Pid/PidCalculator.cpp
CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.o: CMakeFiles/Waves.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.o -MF CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.o.d -o CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.o -c /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Maneuver/Pid/PidCalculator.cpp

CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Maneuver/Pid/PidCalculator.cpp > CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.i

CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Maneuver/Pid/PidCalculator.cpp -o CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.s

CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.o: CMakeFiles/Waves.dir/flags.make
CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.o: /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Mission/MissionController.cpp
CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.o: CMakeFiles/Waves.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.o -MF CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.o.d -o CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.o -c /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Mission/MissionController.cpp

CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Mission/MissionController.cpp > CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.i

CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/Mission/MissionController.cpp -o CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.s

CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.o: CMakeFiles/Waves.dir/flags.make
CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.o: /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/VehicleMain.cpp
CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.o: CMakeFiles/Waves.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.o -MF CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.o.d -o CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.o -c /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/VehicleMain.cpp

CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/VehicleMain.cpp > CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.i

CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Peter/Repos/Waves/src/Vehicle/VehicleMain.cpp -o CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.s

# Object files for target Waves
Waves_OBJECTS = \
"CMakeFiles/Waves.dir/main.cpp.o" \
"CMakeFiles/Waves.dir/src/Sim/Physics.cpp.o" \
"CMakeFiles/Waves.dir/src/Sim/Display.cpp.o" \
"CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.o" \
"CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.o" \
"CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.o" \
"CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.o" \
"CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.o" \
"CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.o" \
"CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.o"

# External object files for target Waves
Waves_EXTERNAL_OBJECTS =

Waves: CMakeFiles/Waves.dir/main.cpp.o
Waves: CMakeFiles/Waves.dir/src/Sim/Physics.cpp.o
Waves: CMakeFiles/Waves.dir/src/Sim/Display.cpp.o
Waves: CMakeFiles/Waves.dir/src/Util/UnitConversion.cpp.o
Waves: CMakeFiles/Waves.dir/src/Util/MathUtils.cpp.o
Waves: CMakeFiles/Waves.dir/src/Util/FrameTransformations.cpp.o
Waves: CMakeFiles/Waves.dir/src/Vehicle/Maneuver/ManeuverController.cpp.o
Waves: CMakeFiles/Waves.dir/src/Vehicle/Maneuver/Pid/PidCalculator.cpp.o
Waves: CMakeFiles/Waves.dir/src/Vehicle/Mission/MissionController.cpp.o
Waves: CMakeFiles/Waves.dir/src/Vehicle/VehicleMain.cpp.o
Waves: CMakeFiles/Waves.dir/build.make
Waves: CMakeFiles/Waves.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Waves"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Waves.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Waves.dir/build: Waves
.PHONY : CMakeFiles/Waves.dir/build

CMakeFiles/Waves.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Waves.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Waves.dir/clean

CMakeFiles/Waves.dir/depend:
	cd /mnt/c/Users/Peter/Repos/Waves/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Peter/Repos/Waves /mnt/c/Users/Peter/Repos/Waves /mnt/c/Users/Peter/Repos/Waves/cmake-build-debug /mnt/c/Users/Peter/Repos/Waves/cmake-build-debug /mnt/c/Users/Peter/Repos/Waves/cmake-build-debug/CMakeFiles/Waves.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Waves.dir/depend

