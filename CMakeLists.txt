cmake_minimum_required(VERSION 3.6)
project(fasta)

set(CMAKE_CX_STANDARD 11)

include_directories("${PROJECT_BINARY_DIR}")

ADD_LIBRARY(lfasta fasta.c)

ADD_EXECUTABLE(main main.c)
TARGET_LINK_LIBRARIES(main lfasta)