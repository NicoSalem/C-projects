# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Users\Nico\OneDrive\Documents\SEMESTER4\CSC 173\eclipse\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Nico\OneDrive\Documents\SEMESTER4\CSC 173\eclipse\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Nico\CLionProjects\proj_1_automata

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Nico\CLionProjects\proj_1_automata\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proj_1_automata.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj_1_automata.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj_1_automata.dir/flags.make

CMakeFiles/proj_1_automata.dir/main.c.obj: CMakeFiles/proj_1_automata.dir/flags.make
CMakeFiles/proj_1_automata.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Nico\CLionProjects\proj_1_automata\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/proj_1_automata.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\proj_1_automata.dir\main.c.obj   -c C:\Users\Nico\CLionProjects\proj_1_automata\main.c

CMakeFiles/proj_1_automata.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/proj_1_automata.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Nico\CLionProjects\proj_1_automata\main.c > CMakeFiles\proj_1_automata.dir\main.c.i

CMakeFiles/proj_1_automata.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/proj_1_automata.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Nico\CLionProjects\proj_1_automata\main.c -o CMakeFiles\proj_1_automata.dir\main.c.s

# Object files for target proj_1_automata
proj_1_automata_OBJECTS = \
"CMakeFiles/proj_1_automata.dir/main.c.obj"

# External object files for target proj_1_automata
proj_1_automata_EXTERNAL_OBJECTS =

proj_1_automata.exe: CMakeFiles/proj_1_automata.dir/main.c.obj
proj_1_automata.exe: CMakeFiles/proj_1_automata.dir/build.make
proj_1_automata.exe: CMakeFiles/proj_1_automata.dir/linklibs.rsp
proj_1_automata.exe: CMakeFiles/proj_1_automata.dir/objects1.rsp
proj_1_automata.exe: CMakeFiles/proj_1_automata.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Nico\CLionProjects\proj_1_automata\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable proj_1_automata.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\proj_1_automata.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj_1_automata.dir/build: proj_1_automata.exe

.PHONY : CMakeFiles/proj_1_automata.dir/build

CMakeFiles/proj_1_automata.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\proj_1_automata.dir\cmake_clean.cmake
.PHONY : CMakeFiles/proj_1_automata.dir/clean

CMakeFiles/proj_1_automata.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Nico\CLionProjects\proj_1_automata C:\Users\Nico\CLionProjects\proj_1_automata C:\Users\Nico\CLionProjects\proj_1_automata\cmake-build-debug C:\Users\Nico\CLionProjects\proj_1_automata\cmake-build-debug C:\Users\Nico\CLionProjects\proj_1_automata\cmake-build-debug\CMakeFiles\proj_1_automata.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj_1_automata.dir/depend
