cmake_minimum_required(VERSION 3.10)
project(SFMLSnake)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC_FILES src/*)

add_executable(Test main.cpp )
target_link_libraries(Test sfml-graphics sfml-window sfml-system sfml-network sfml-audio)

add_executable(Main ${SRC_FILES})
target_link_libraries(Main sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
