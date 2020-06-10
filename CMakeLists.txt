cmake_minimum_required(VERSION 3.15)
project(mraytracer)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(glm)
add_subdirectory(Shapes)
add_subdirectory(Scene)
add_executable(mraytracer main.cpp)

target_link_libraries(mraytracer PRIVATE shapes)
target_link_libraries(mraytracer PRIVATE scene)
