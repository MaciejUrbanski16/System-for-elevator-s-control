# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\Admin\Desktop\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Admin\Desktop\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Admin\Desktop\elevators

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Admin\Desktop\elevators\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/elevators.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/elevators.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/elevators.dir/flags.make

CMakeFiles/elevators.dir/main.c.obj: CMakeFiles/elevators.dir/flags.make
CMakeFiles/elevators.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Admin\Desktop\elevators\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/elevators.dir/main.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\elevators.dir\main.c.obj   -c C:\Users\Admin\Desktop\elevators\main.c

CMakeFiles/elevators.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/elevators.dir/main.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Admin\Desktop\elevators\main.c > CMakeFiles\elevators.dir\main.c.i

CMakeFiles/elevators.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/elevators.dir/main.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Admin\Desktop\elevators\main.c -o CMakeFiles\elevators.dir\main.c.s

CMakeFiles/elevators.dir/elevator.c.obj: CMakeFiles/elevators.dir/flags.make
CMakeFiles/elevators.dir/elevator.c.obj: ../elevator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Admin\Desktop\elevators\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/elevators.dir/elevator.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\elevators.dir\elevator.c.obj   -c C:\Users\Admin\Desktop\elevators\elevator.c

CMakeFiles/elevators.dir/elevator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/elevators.dir/elevator.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Admin\Desktop\elevators\elevator.c > CMakeFiles\elevators.dir\elevator.c.i

CMakeFiles/elevators.dir/elevator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/elevators.dir/elevator.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Admin\Desktop\elevators\elevator.c -o CMakeFiles\elevators.dir\elevator.c.s

CMakeFiles/elevators.dir/status.c.obj: CMakeFiles/elevators.dir/flags.make
CMakeFiles/elevators.dir/status.c.obj: ../status.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Admin\Desktop\elevators\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/elevators.dir/status.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\elevators.dir\status.c.obj   -c C:\Users\Admin\Desktop\elevators\status.c

CMakeFiles/elevators.dir/status.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/elevators.dir/status.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Admin\Desktop\elevators\status.c > CMakeFiles\elevators.dir\status.c.i

CMakeFiles/elevators.dir/status.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/elevators.dir/status.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Admin\Desktop\elevators\status.c -o CMakeFiles\elevators.dir\status.c.s

# Object files for target elevators
elevators_OBJECTS = \
"CMakeFiles/elevators.dir/main.c.obj" \
"CMakeFiles/elevators.dir/elevator.c.obj" \
"CMakeFiles/elevators.dir/status.c.obj"

# External object files for target elevators
elevators_EXTERNAL_OBJECTS =

elevators.exe: CMakeFiles/elevators.dir/main.c.obj
elevators.exe: CMakeFiles/elevators.dir/elevator.c.obj
elevators.exe: CMakeFiles/elevators.dir/status.c.obj
elevators.exe: CMakeFiles/elevators.dir/build.make
elevators.exe: CMakeFiles/elevators.dir/linklibs.rsp
elevators.exe: CMakeFiles/elevators.dir/objects1.rsp
elevators.exe: CMakeFiles/elevators.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Admin\Desktop\elevators\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable elevators.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\elevators.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/elevators.dir/build: elevators.exe

.PHONY : CMakeFiles/elevators.dir/build

CMakeFiles/elevators.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\elevators.dir\cmake_clean.cmake
.PHONY : CMakeFiles/elevators.dir/clean

CMakeFiles/elevators.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Admin\Desktop\elevators C:\Users\Admin\Desktop\elevators C:\Users\Admin\Desktop\elevators\cmake-build-debug C:\Users\Admin\Desktop\elevators\cmake-build-debug C:\Users\Admin\Desktop\elevators\cmake-build-debug\CMakeFiles\elevators.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/elevators.dir/depend

