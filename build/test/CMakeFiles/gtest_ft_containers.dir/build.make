# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Users/frthierr/.brew/Cellar/cmake/3.20.2/bin/cmake

# The command to remove a file.
RM = /Users/frthierr/.brew/Cellar/cmake/3.20.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/frthierr/workplace/ft_containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/frthierr/workplace/ft_containers/build

# Include any dependencies generated for this target.
include test/CMakeFiles/gtest_ft_containers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/gtest_ft_containers.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/gtest_ft_containers.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/gtest_ft_containers.dir/flags.make

test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.o: test/CMakeFiles/gtest_ft_containers.dir/flags.make
test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.o: ../test/srcs/helpers/Tpair.cpp
test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.o: test/CMakeFiles/gtest_ft_containers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frthierr/workplace/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.o"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.o -MF CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.o.d -o CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.o -c /Users/frthierr/workplace/ft_containers/test/srcs/helpers/Tpair.cpp

test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.i"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frthierr/workplace/ft_containers/test/srcs/helpers/Tpair.cpp > CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.i

test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.s"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frthierr/workplace/ft_containers/test/srcs/helpers/Tpair.cpp -o CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.s

test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.o: test/CMakeFiles/gtest_ft_containers.dir/flags.make
test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.o: ../test/srcs/helpers/Tcompare.cpp
test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.o: test/CMakeFiles/gtest_ft_containers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frthierr/workplace/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.o"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.o -MF CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.o.d -o CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.o -c /Users/frthierr/workplace/ft_containers/test/srcs/helpers/Tcompare.cpp

test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.i"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frthierr/workplace/ft_containers/test/srcs/helpers/Tcompare.cpp > CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.i

test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.s"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frthierr/workplace/ft_containers/test/srcs/helpers/Tcompare.cpp -o CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.s

test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.o: test/CMakeFiles/gtest_ft_containers.dir/flags.make
test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.o: ../test/srcs/map/TMap_Constructors.cpp
test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.o: test/CMakeFiles/gtest_ft_containers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frthierr/workplace/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.o"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.o -MF CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.o.d -o CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.o -c /Users/frthierr/workplace/ft_containers/test/srcs/map/TMap_Constructors.cpp

test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.i"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frthierr/workplace/ft_containers/test/srcs/map/TMap_Constructors.cpp > CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.i

test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.s"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frthierr/workplace/ft_containers/test/srcs/map/TMap_Constructors.cpp -o CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.s

test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.o: test/CMakeFiles/gtest_ft_containers.dir/flags.make
test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.o: ../test/srcs/map/TMap_Modifiers.cpp
test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.o: test/CMakeFiles/gtest_ft_containers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frthierr/workplace/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.o"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.o -MF CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.o.d -o CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.o -c /Users/frthierr/workplace/ft_containers/test/srcs/map/TMap_Modifiers.cpp

test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.i"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frthierr/workplace/ft_containers/test/srcs/map/TMap_Modifiers.cpp > CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.i

test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.s"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frthierr/workplace/ft_containers/test/srcs/map/TMap_Modifiers.cpp -o CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.s

test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.o: test/CMakeFiles/gtest_ft_containers.dir/flags.make
test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.o: ../test/srcs/map/TMap_Iterators.cpp
test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.o: test/CMakeFiles/gtest_ft_containers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frthierr/workplace/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.o"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.o -MF CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.o.d -o CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.o -c /Users/frthierr/workplace/ft_containers/test/srcs/map/TMap_Iterators.cpp

test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.i"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frthierr/workplace/ft_containers/test/srcs/map/TMap_Iterators.cpp > CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.i

test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.s"
	cd /Users/frthierr/workplace/ft_containers/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frthierr/workplace/ft_containers/test/srcs/map/TMap_Iterators.cpp -o CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.s

# Object files for target gtest_ft_containers
gtest_ft_containers_OBJECTS = \
"CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.o" \
"CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.o" \
"CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.o" \
"CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.o" \
"CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.o"

# External object files for target gtest_ft_containers
gtest_ft_containers_EXTERNAL_OBJECTS =

test/gtest_ft_containers: test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tpair.cpp.o
test/gtest_ft_containers: test/CMakeFiles/gtest_ft_containers.dir/srcs/helpers/Tcompare.cpp.o
test/gtest_ft_containers: test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Constructors.cpp.o
test/gtest_ft_containers: test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Modifiers.cpp.o
test/gtest_ft_containers: test/CMakeFiles/gtest_ft_containers.dir/srcs/map/TMap_Iterators.cpp.o
test/gtest_ft_containers: test/CMakeFiles/gtest_ft_containers.dir/build.make
test/gtest_ft_containers: lib/libgtest_maind.a
test/gtest_ft_containers: lib/libgtestd.a
test/gtest_ft_containers: test/CMakeFiles/gtest_ft_containers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/frthierr/workplace/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable gtest_ft_containers"
	cd /Users/frthierr/workplace/ft_containers/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_ft_containers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/gtest_ft_containers.dir/build: test/gtest_ft_containers
.PHONY : test/CMakeFiles/gtest_ft_containers.dir/build

test/CMakeFiles/gtest_ft_containers.dir/clean:
	cd /Users/frthierr/workplace/ft_containers/build/test && $(CMAKE_COMMAND) -P CMakeFiles/gtest_ft_containers.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/gtest_ft_containers.dir/clean

test/CMakeFiles/gtest_ft_containers.dir/depend:
	cd /Users/frthierr/workplace/ft_containers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/frthierr/workplace/ft_containers /Users/frthierr/workplace/ft_containers/test /Users/frthierr/workplace/ft_containers/build /Users/frthierr/workplace/ft_containers/build/test /Users/frthierr/workplace/ft_containers/build/test/CMakeFiles/gtest_ft_containers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/gtest_ft_containers.dir/depend

