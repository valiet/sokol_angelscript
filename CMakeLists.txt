cmake_minimum_required(VERSION 3.10)

project(sokol_angelscript)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(angelscript/projects/cmake)

add_library(cangelscript STATIC cangelscript/cangelscript.cpp cangelscript/cangelscript.h)
target_compile_definitions(cangelscript PRIVATE -DANGELSCRIPT_EXPORT -DAS_C_INTERFACE -D_LIB)
target_link_libraries(cangelscript PUBLIC angelscript)
target_include_directories(cangelscript INTERFACE cangelscript)

add_executable(sokol_angelscript main.c)
target_include_directories(sokol_angelscript PUBLIC cangelscript/ sokol/)
target_link_libraries(sokol_angelscript PUBLIC cangelscript)
set_target_properties(sokol_angelscript PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
