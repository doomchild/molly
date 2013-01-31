cmake_minimum_required (VERSION 2.6)
project (molly)

set (molly_VERSION_MAJOR 0)
set (molly_VERSION_MINOR 1)

set (CMAKE_INSTALL_PREFIX /home/doomchild/code/molly)
list (APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include_directories("${PROJECT_BINARY_DIR}")

find_package (GLIB2 REQUIRED)
include_directories (${GLIB2_INCLUDE_DIRS})

add_executable(molly lexer.c ast.c)
target_link_libraries (molly ${GLIB2_LIBRARIES})

install (TARGETS molly DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/version.h" DESTINATION include)