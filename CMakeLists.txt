cmake_minimum_required(VERSION 3.21)
project(SortVisualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# sfml
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")          #[[ZMIEN TO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!]]
find_package(SFML 2.5.1 COMPONENTS graphics window system network audio REQUIRED)

file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_SOURCE_DIR} "./src/*.cpp")
add_executable(SortVisualizer ${SOURCE_FILES})
target_link_libraries(SortVisualizer sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
