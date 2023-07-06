cmake_minimum_required(VERSION 3.7)

project(Engine)

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

if(POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Deps/raylib" "${CMAKE_CURRENT_BINARY_DIR}/Deps/raylib")
set_target_properties(raylib PROPERTIES FOLDER "Deps")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Deps/pugixml" "${CMAKE_CURRENT_BINARY_DIR}/Deps/pugixml")
set_target_properties(pugixml-static PROPERTIES FOLDER "Deps")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Deps/entt" "${CMAKE_CURRENT_BINARY_DIR}/Deps/entt")
set_target_properties(EnTT PROPERTIES FOLDER "Deps")

include(CMake/src.cmake)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/Src" FILES ${ENGINE_HEADERS} ${ENGINE_SOURCES})
add_library(Engine ${ENGINE_HEADERS} ${ENGINE_SOURCES})
target_include_directories(Engine PUBLIC Src)
target_link_libraries(Engine PUBLIC 
	raylib
	pugixml-static
	EnTT
)
