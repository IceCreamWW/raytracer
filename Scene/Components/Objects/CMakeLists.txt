add_library(material Material.cpp Material.hpp)
target_include_directories(material PUBLIC .)
target_link_libraries(material PUBLIC glm)


add_library(objects Object.cpp Sphere.cpp)
target_include_directories(objects PUBLIC .)
target_link_libraries(objects PUBLIC glm)
target_link_libraries(objects PUBLIC material)




