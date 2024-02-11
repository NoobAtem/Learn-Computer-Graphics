cmake_minimum_required(VERSION 3.10)

project(graphics)

find_package(SDL2 REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB_RECURSE SRC "src/*.c")
file(GLOB_RECURSE HEADER "src/*.h")

add_library(static_graphics STATIC ${SRC} ${HEADER})

if (WIN32)
    add_library(dynamic_graphics SHARED ${SRC} ${HEADER})
else()
    add_library(dynamic_graphics SHARED ${SRC} ${HEADER})
endif()

add_executable(graphics test.c ${SRC} ${HEADER})

target_compile_options(graphics PRIVATE -Wall -Wextra)

target_link_libraries(graphics ${SDL2_LIBRARIES} static_graphics dynamic_graphics)

