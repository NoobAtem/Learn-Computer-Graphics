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
CMAKE_SOURCE_DIR = "/home/noob212/Documents/Computer Science/Graphics"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/noob212/Documents/Computer Science/Graphics"

# Include any dependencies generated for this target.
include CMakeFiles/graphics.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/graphics.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/graphics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphics.dir/flags.make

CMakeFiles/graphics.dir/test.c.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/test.c.o: test.c
CMakeFiles/graphics.dir/test.c.o: CMakeFiles/graphics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/noob212/Documents/Computer Science/Graphics/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/graphics.dir/test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/graphics.dir/test.c.o -MF CMakeFiles/graphics.dir/test.c.o.d -o CMakeFiles/graphics.dir/test.c.o -c "/home/noob212/Documents/Computer Science/Graphics/test.c"

CMakeFiles/graphics.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/graphics.dir/test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/noob212/Documents/Computer Science/Graphics/test.c" > CMakeFiles/graphics.dir/test.c.i

CMakeFiles/graphics.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/graphics.dir/test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/noob212/Documents/Computer Science/Graphics/test.c" -o CMakeFiles/graphics.dir/test.c.s

CMakeFiles/graphics.dir/src/gcl_geometry.c.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/gcl_geometry.c.o: src/gcl_geometry.c
CMakeFiles/graphics.dir/src/gcl_geometry.c.o: CMakeFiles/graphics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/noob212/Documents/Computer Science/Graphics/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/graphics.dir/src/gcl_geometry.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/graphics.dir/src/gcl_geometry.c.o -MF CMakeFiles/graphics.dir/src/gcl_geometry.c.o.d -o CMakeFiles/graphics.dir/src/gcl_geometry.c.o -c "/home/noob212/Documents/Computer Science/Graphics/src/gcl_geometry.c"

CMakeFiles/graphics.dir/src/gcl_geometry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/graphics.dir/src/gcl_geometry.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/noob212/Documents/Computer Science/Graphics/src/gcl_geometry.c" > CMakeFiles/graphics.dir/src/gcl_geometry.c.i

CMakeFiles/graphics.dir/src/gcl_geometry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/graphics.dir/src/gcl_geometry.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/noob212/Documents/Computer Science/Graphics/src/gcl_geometry.c" -o CMakeFiles/graphics.dir/src/gcl_geometry.c.s

CMakeFiles/graphics.dir/src/gcl_init.c.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/gcl_init.c.o: src/gcl_init.c
CMakeFiles/graphics.dir/src/gcl_init.c.o: CMakeFiles/graphics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/noob212/Documents/Computer Science/Graphics/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/graphics.dir/src/gcl_init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/graphics.dir/src/gcl_init.c.o -MF CMakeFiles/graphics.dir/src/gcl_init.c.o.d -o CMakeFiles/graphics.dir/src/gcl_init.c.o -c "/home/noob212/Documents/Computer Science/Graphics/src/gcl_init.c"

CMakeFiles/graphics.dir/src/gcl_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/graphics.dir/src/gcl_init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/noob212/Documents/Computer Science/Graphics/src/gcl_init.c" > CMakeFiles/graphics.dir/src/gcl_init.c.i

CMakeFiles/graphics.dir/src/gcl_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/graphics.dir/src/gcl_init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/noob212/Documents/Computer Science/Graphics/src/gcl_init.c" -o CMakeFiles/graphics.dir/src/gcl_init.c.s

CMakeFiles/graphics.dir/src/gcl_math.c.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/gcl_math.c.o: src/gcl_math.c
CMakeFiles/graphics.dir/src/gcl_math.c.o: CMakeFiles/graphics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/noob212/Documents/Computer Science/Graphics/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/graphics.dir/src/gcl_math.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/graphics.dir/src/gcl_math.c.o -MF CMakeFiles/graphics.dir/src/gcl_math.c.o.d -o CMakeFiles/graphics.dir/src/gcl_math.c.o -c "/home/noob212/Documents/Computer Science/Graphics/src/gcl_math.c"

CMakeFiles/graphics.dir/src/gcl_math.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/graphics.dir/src/gcl_math.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/noob212/Documents/Computer Science/Graphics/src/gcl_math.c" > CMakeFiles/graphics.dir/src/gcl_math.c.i

CMakeFiles/graphics.dir/src/gcl_math.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/graphics.dir/src/gcl_math.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/noob212/Documents/Computer Science/Graphics/src/gcl_math.c" -o CMakeFiles/graphics.dir/src/gcl_math.c.s

# Object files for target graphics
graphics_OBJECTS = \
"CMakeFiles/graphics.dir/test.c.o" \
"CMakeFiles/graphics.dir/src/gcl_geometry.c.o" \
"CMakeFiles/graphics.dir/src/gcl_init.c.o" \
"CMakeFiles/graphics.dir/src/gcl_math.c.o"

# External object files for target graphics
graphics_EXTERNAL_OBJECTS =

bin/graphics: CMakeFiles/graphics.dir/test.c.o
bin/graphics: CMakeFiles/graphics.dir/src/gcl_geometry.c.o
bin/graphics: CMakeFiles/graphics.dir/src/gcl_init.c.o
bin/graphics: CMakeFiles/graphics.dir/src/gcl_math.c.o
bin/graphics: CMakeFiles/graphics.dir/build.make
bin/graphics: lib/libstatic_graphics.a
bin/graphics: lib/libdynamic_graphics.so
bin/graphics: CMakeFiles/graphics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/noob212/Documents/Computer Science/Graphics/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable bin/graphics"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphics.dir/build: bin/graphics
.PHONY : CMakeFiles/graphics.dir/build

CMakeFiles/graphics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graphics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graphics.dir/clean

CMakeFiles/graphics.dir/depend:
	cd "/home/noob212/Documents/Computer Science/Graphics" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/noob212/Documents/Computer Science/Graphics" "/home/noob212/Documents/Computer Science/Graphics" "/home/noob212/Documents/Computer Science/Graphics" "/home/noob212/Documents/Computer Science/Graphics" "/home/noob212/Documents/Computer Science/Graphics/CMakeFiles/graphics.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/graphics.dir/depend
