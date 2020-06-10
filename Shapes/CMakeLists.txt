add_library(shapes Shape.cpp Sphere.cpp Color.hpp)
target_include_directories(shapes PUBLIC .)
target_link_libraries(shapes PUBLIC glm)


