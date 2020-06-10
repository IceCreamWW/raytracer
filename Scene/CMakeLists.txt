add_library(scene STATIC Image.cpp Scene.cpp)
target_link_libraries(scene PUBLIC shapes)
