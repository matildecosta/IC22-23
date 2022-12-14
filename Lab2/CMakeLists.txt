cmake_minimum_required(VERSION 3.16)
project(lab2)

find_package(OpenCV REQUIRED)

SET (CMAKE_BUILD_TYPE "Release")
SET (CMAKE_BUILD_TYPE "Debug")

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++17")
SET (CMAKE_CXX_FLAGS_RELEASE "-O3")
SET (CMAKE_CXX_FLAGS_DEBUG "-g3 -fsanitize=address")

SET (BASE_DIR ${CMAKE_SOURCE_DIR} )
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BASE_DIR}/opencv-example-bin)

add_executable (copy copy.cpp)
target_link_libraries (copy ${OpenCV_LIBS})

add_executable (ex2 ex2.cpp)
target_link_libraries (ex2 ${OpenCV_LIBS})

add_executable (ex3 ex3.cpp)
target_link_libraries (ex3 ${OpenCV_LIBS})

add_executable (ex4 codec4.cpp)
target_link_libraries (ex4 sndfile)

add_executable (ex6 codec6.cpp)
target_link_libraries (ex6 ${OpenCV_LIBS})
