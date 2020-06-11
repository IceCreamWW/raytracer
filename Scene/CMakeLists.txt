add_subdirectory(Components)

add_library(scene STATIC Image.cpp Scene.cpp)
target_include_directories(scene PUBLIC .)
target_link_libraries(scene PUBLIC objects)
target_link_libraries(scene PUBLIC light)
