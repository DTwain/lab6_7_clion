# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\INFO 2\SEM 2\oop_lab_6_9"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab6_7_clion.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab6_7_clion.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab6_7_clion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6_7_clion.dir/flags.make

CMakeFiles/lab6_7_clion.dir/main.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/main.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/main.cpp
CMakeFiles/lab6_7_clion.dir/main.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab6_7_clion.dir/main.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/main.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\main.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\main.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\main.cpp"

CMakeFiles/lab6_7_clion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/main.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\main.cpp" > CMakeFiles\lab6_7_clion.dir\main.cpp.i

CMakeFiles/lab6_7_clion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/main.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\main.cpp" -o CMakeFiles\lab6_7_clion.dir\main.cpp.s

CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/domain/carte.cpp
CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\domain\carte.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\domain\carte.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\domain\carte.cpp"

CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\domain\carte.cpp" > CMakeFiles\lab6_7_clion.dir\domain\carte.cpp.i

CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\domain\carte.cpp" -o CMakeFiles\lab6_7_clion.dir\domain\carte.cpp.s

CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/repository/repo.cpp
CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\repository\repo.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\repository\repo.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\repository\repo.cpp"

CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\repository\repo.cpp" > CMakeFiles\lab6_7_clion.dir\repository\repo.cpp.i

CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\repository\repo.cpp" -o CMakeFiles\lab6_7_clion.dir\repository\repo.cpp.s

CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/service/service_biblioteca.cpp
CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\service\service_biblioteca.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\service\service_biblioteca.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\service\service_biblioteca.cpp"

CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\service\service_biblioteca.cpp" > CMakeFiles\lab6_7_clion.dir\service\service_biblioteca.cpp.i

CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\service\service_biblioteca.cpp" -o CMakeFiles\lab6_7_clion.dir\service\service_biblioteca.cpp.s

CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/ui/ui_biblioteca.cpp
CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\ui\ui_biblioteca.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\ui\ui_biblioteca.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\ui\ui_biblioteca.cpp"

CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\ui\ui_biblioteca.cpp" > CMakeFiles\lab6_7_clion.dir\ui\ui_biblioteca.cpp.i

CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\ui\ui_biblioteca.cpp" -o CMakeFiles\lab6_7_clion.dir\ui\ui_biblioteca.cpp.s

CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/teste/test_repo.cpp
CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\teste\test_repo.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\teste\test_repo.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_repo.cpp"

CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_repo.cpp" > CMakeFiles\lab6_7_clion.dir\teste\test_repo.cpp.i

CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_repo.cpp" -o CMakeFiles\lab6_7_clion.dir\teste\test_repo.cpp.s

CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/teste/test_domain.cpp
CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\teste\test_domain.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\teste\test_domain.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_domain.cpp"

CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_domain.cpp" > CMakeFiles\lab6_7_clion.dir\teste\test_domain.cpp.i

CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_domain.cpp" -o CMakeFiles\lab6_7_clion.dir\teste\test_domain.cpp.s

CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/domain/validator.cpp
CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\domain\validator.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\domain\validator.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\domain\validator.cpp"

CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\domain\validator.cpp" > CMakeFiles\lab6_7_clion.dir\domain\validator.cpp.i

CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\domain\validator.cpp" -o CMakeFiles\lab6_7_clion.dir\domain\validator.cpp.s

CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/teste/test_validator.cpp
CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\teste\test_validator.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\teste\test_validator.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_validator.cpp"

CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_validator.cpp" > CMakeFiles\lab6_7_clion.dir\teste\test_validator.cpp.i

CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_validator.cpp" -o CMakeFiles\lab6_7_clion.dir\teste\test_validator.cpp.s

CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/teste/test_service.cpp
CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\teste\test_service.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\teste\test_service.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_service.cpp"

CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_service.cpp" > CMakeFiles\lab6_7_clion.dir\teste\test_service.cpp.i

CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_service.cpp" -o CMakeFiles\lab6_7_clion.dir\teste\test_service.cpp.s

CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/service/cos_carti.cpp
CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\service\cos_carti.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\service\cos_carti.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\service\cos_carti.cpp"

CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\service\cos_carti.cpp" > CMakeFiles\lab6_7_clion.dir\service\cos_carti.cpp.i

CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\service\cos_carti.cpp" -o CMakeFiles\lab6_7_clion.dir\service\cos_carti.cpp.s

CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.obj: CMakeFiles/lab6_7_clion.dir/flags.make
CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.obj: D:/INFO\ 2/SEM\ 2/oop_lab_6_9/teste/test_cos_srv.cpp
CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.obj: CMakeFiles/lab6_7_clion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.obj"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.obj -MF CMakeFiles\lab6_7_clion.dir\teste\test_cos_srv.cpp.obj.d -o CMakeFiles\lab6_7_clion.dir\teste\test_cos_srv.cpp.obj -c "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_cos_srv.cpp"

CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.i"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_cos_srv.cpp" > CMakeFiles\lab6_7_clion.dir\teste\test_cos_srv.cpp.i

CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.s"
	"D:\CLion 2023.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\INFO 2\SEM 2\oop_lab_6_9\teste\test_cos_srv.cpp" -o CMakeFiles\lab6_7_clion.dir\teste\test_cos_srv.cpp.s

# Object files for target lab6_7_clion
lab6_7_clion_OBJECTS = \
"CMakeFiles/lab6_7_clion.dir/main.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.obj" \
"CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.obj"

# External object files for target lab6_7_clion
lab6_7_clion_EXTERNAL_OBJECTS =

lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/main.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/domain/carte.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/repository/repo.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/service/service_biblioteca.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/ui/ui_biblioteca.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/teste/test_repo.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/teste/test_domain.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/domain/validator.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/teste/test_validator.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/teste/test_service.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/service/cos_carti.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/teste/test_cos_srv.cpp.obj
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/build.make
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/linkLibs.rsp
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/objects1.rsp
lab6_7_clion.exe: CMakeFiles/lab6_7_clion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable lab6_7_clion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab6_7_clion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6_7_clion.dir/build: lab6_7_clion.exe
.PHONY : CMakeFiles/lab6_7_clion.dir/build

CMakeFiles/lab6_7_clion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab6_7_clion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab6_7_clion.dir/clean

CMakeFiles/lab6_7_clion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\INFO 2\SEM 2\oop_lab_6_9" "D:\INFO 2\SEM 2\oop_lab_6_9" "D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug" "D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug" "D:\INFO 2\SEM 2\oop_lab_6_9\cmake-build-debug\CMakeFiles\lab6_7_clion.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/lab6_7_clion.dir/depend

