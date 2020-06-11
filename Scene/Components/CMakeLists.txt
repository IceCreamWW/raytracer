add_subdirectory(Objects)

# add_library(objects Object.cpp Sphere.cpp Color.hpp)
add_library(light Light.cpp)
target_include_directories(light PUBLIC .)
target_link_libraries(light PUBLIC glm)

