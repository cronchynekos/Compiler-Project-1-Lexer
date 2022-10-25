cmake_minimum_required (VERSION 3.11)

enable_language(CXX)
set(CMAKE_CXX_FLAGS "-g -Wall")

project (Compiler)

include_directories(.)
include_directories("./include")

set (Compiler_VERSION_MAJOR 0)
set (Compiler_VERSION_MINOR 1)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.x
)

FetchContent_MakeAvailable(Catch2)

# Discover source and header files
file(GLOB_RECURSE Compiler_SOURCES "src/*.cpp")
file(GLOB_RECURSE Compiler_HEADERS "include/*.h")
file(GLOB_RECURSE Compiler_TESTS "test/*.cpp")

set(Compiler_INCLUDE_DIRS "")
foreach(_headerFile ${Compiler_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND Compiler_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Compiler_INCLUDE_DIRS)

# Link compiler into shared library.
add_library(CompileLib SHARED ${Compiler_SOURCES})
target_include_directories(CompileLib PRIVATE ${Compiler_INCLUDE_DIRS})
install(TARGETS CompileLib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(MAIN "src/main.cpp")

# Define the Compiler run configuration
add_executable(Compiler.out ${MAIN})
set_target_properties(Compiler.out PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Compiler.out PRIVATE ${Compiler_INCLUDE_DIRS})
target_link_libraries(Compiler.out CompileLib)

# Define the Test run configuration
add_executable(Test.out ${Compiler_TESTS})
target_compile_definitions(Test.out PRIVATE TEST_BUILD)
set_target_properties(Test.out PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Test.out PRIVATE ${Compiler_INCLUDE_DIRS})
target_link_libraries(Test.out CompileLib Catch2::Catch2)
