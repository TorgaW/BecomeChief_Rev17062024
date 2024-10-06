cmake_minimum_required(VERSION 3.13) # CMake version check
project(VulpeculaEngine) # Create project "simple_example"
set(CMAKE_CXX_STANDARD 23) # Enable c++14 standard

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(VULPECULA_SRC_PATH ${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE VULPECULA_SRC
     ${CMAKE_SOURCE_DIR}/src/*.c
     ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES main.cpp ${VULPECULA_SRC})

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(VulpeculaEngine ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${VULPECULA_SRC_PATH})
target_link_libraries(VulpeculaEngine SDL2 SDL2_image)

add_custom_target(copy_assets_engine ALL
     COMMAND ${CMAKE_COMMAND} -E copy_directory
     ${PROJECT_SOURCE_DIR}/assets
     ${PROJECT_BINARY_DIR}/assets
     COMMENT "Copying engine assets into binary directory")