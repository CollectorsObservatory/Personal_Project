# Create the library from the source files
add_library(tugabudoire STATIC Tugabudoire.cpp)

# Specify include directories for the library
target_include_directories(tugabudoire PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(tugabudoire PUBLIC cxx_std_14)
