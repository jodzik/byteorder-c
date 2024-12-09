cmake_minimum_required(VERSION 3.28)

project(byteorder-c)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)

add_library(byteorder-c STATIC ${SRC})

target_include_directories(byteorder-c PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
