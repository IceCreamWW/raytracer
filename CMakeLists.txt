cmake_minimum_required(VERSION 3.15)
project(mraytracer)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(glm)
add_subdirectory(Scene)

add_executable(mraytracer main.cpp)

target_link_libraries(mraytracer PUBLIC scene)
target_link_libraries(mraytracer PUBLIC objects)
target_link_libraries(mraytracer PUBLIC light)
