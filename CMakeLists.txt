cmake_minimum_required(VERSION 3.21)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c23")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(BecomeChiefRev17062024)

set(VULPECULA_SRC_PATH VulpeculaEngine/src)
set(VULPECULA_INCLUDE_PATH VulpeculaEngine/include)
set(GAME_SRC Game/src)
set(GAME_INCLUDE Game/include)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB_RECURSE VULPECULA_SRC 
     ${CMAKE_SOURCE_DIR}/VulpeculaEngine/src/*.c
     ${CMAKE_SOURCE_DIR}/VulpeculaEngine/src/*.cpp)

message(DEBUG ${VULPECULA_SRC})

add_executable(BecomeChiefRev17062024 ${GAME_SRC}/main.c ${VULPECULA_SRC})

set_target_properties(BecomeChiefRev17062024 PROPERTIES LINKER_LANGUAGE C)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(BecomeChiefRev17062024 SDL2 SDL2_image)

# command to update resources every build
add_custom_target(copy_resources_engine ALL                                                                                                                                              
        COMMAND ${CMAKE_COMMAND} -E copy_directory                                                                                                                                
        ${PROJECT_SOURCE_DIR}/VulpeculaEngine/resources                                                                                                                                           
        ${PROJECT_BINARY_DIR}/VulpeculaEngine/resources                                                                                                                                           
        COMMENT "Copying engine resources into binary directory")

add_custom_target(copy_resources_game ALL                                                                                                                                              
        COMMAND ${CMAKE_COMMAND} -E copy_directory                                                                                                                                
        ${PROJECT_SOURCE_DIR}/Game/resources                                                                                                                                           
        ${PROJECT_BINARY_DIR}/Game/resources                                                                                                                                           
        COMMENT "Copying game resources into binary directory") 
