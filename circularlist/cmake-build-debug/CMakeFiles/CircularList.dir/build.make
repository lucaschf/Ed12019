# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CircularList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CircularList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CircularList.dir/flags.make

CMakeFiles/CircularList.dir/lista.c.obj: CMakeFiles/CircularList.dir/flags.make
CMakeFiles/CircularList.dir/lista.c.obj: CMakeFiles/CircularList.dir/includes_C.rsp
CMakeFiles/CircularList.dir/lista.c.obj: ../lista.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CircularList.dir/lista.c.obj"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\CircularList.dir\lista.c.obj   -c C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\lista.c

CMakeFiles/CircularList.dir/lista.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CircularList.dir/lista.c.i"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\lista.c > CMakeFiles\CircularList.dir\lista.c.i

CMakeFiles/CircularList.dir/lista.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CircularList.dir/lista.c.s"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\lista.c -o CMakeFiles\CircularList.dir\lista.c.s

CMakeFiles/CircularList.dir/main.c.obj: CMakeFiles/CircularList.dir/flags.make
CMakeFiles/CircularList.dir/main.c.obj: CMakeFiles/CircularList.dir/includes_C.rsp
CMakeFiles/CircularList.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CircularList.dir/main.c.obj"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\CircularList.dir\main.c.obj   -c C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\main.c

CMakeFiles/CircularList.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CircularList.dir/main.c.i"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\main.c > CMakeFiles\CircularList.dir\main.c.i

CMakeFiles/CircularList.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CircularList.dir/main.c.s"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\main.c -o CMakeFiles\CircularList.dir\main.c.s

# Object files for target CircularList
CircularList_OBJECTS = \
"CMakeFiles/CircularList.dir/lista.c.obj" \
"CMakeFiles/CircularList.dir/main.c.obj"

# External object files for target CircularList
CircularList_EXTERNAL_OBJECTS =

CircularList.exe: CMakeFiles/CircularList.dir/lista.c.obj
CircularList.exe: CMakeFiles/CircularList.dir/main.c.obj
CircularList.exe: CMakeFiles/CircularList.dir/build.make
CircularList.exe: CMakeFiles/CircularList.dir/linklibs.rsp
CircularList.exe: CMakeFiles/CircularList.dir/objects1.rsp
CircularList.exe: CMakeFiles/CircularList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable CircularList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CircularList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CircularList.dir/build: CircularList.exe

.PHONY : CMakeFiles/CircularList.dir/build

CMakeFiles/CircularList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CircularList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CircularList.dir/clean

CMakeFiles/CircularList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1 C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1 C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\cmake-build-debug C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\cmake-build-debug C:\Users\lucas\Desktop\lucascristovam-circularlist-54a990b94ef1\cmake-build-debug\CMakeFiles\CircularList.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CircularList.dir/depend

