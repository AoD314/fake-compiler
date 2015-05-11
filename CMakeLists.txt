cmake_minimum_required(VERSION 3.2)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(cmake/general.cmake)

set_dependency("mlib")

add_app("fake-compiler" "src")

set_solution("fake-compiler")