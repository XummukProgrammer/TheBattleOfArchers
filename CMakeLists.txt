cmake_minimum_required(VERSION 3.7)

project(TheBattleOfArchers)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT TheBattleOfArchers)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Engine" "${CMAKE_CURRENT_BINARY_DIR}/Engine")

include(CMake/src.cmake)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/Src" FILES ${GAME_HEADERS} ${GAME_SOURCES})
add_executable(TheBattleOfArchers ${GAME_HEADERS} ${GAME_SOURCES})
target_link_libraries(TheBattleOfArchers PRIVATE Engine)
target_include_directories(TheBattleOfArchers PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Src")

set(GAME_BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Bin/$<$<BOOL:FALSE>:>")

set_target_properties(TheBattleOfArchers PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${GAME_BIN_DIR}
	DEBUG_POSTFIX "_d"
	CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON
)
