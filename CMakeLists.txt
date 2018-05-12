cmake_minimum_required (VERSION 3.11)

set (CMAKE_CXX_COMPILER g++)
set (CMAKE_C_COMPILER gcc)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project (Project)
enable_language (CXX)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON) 
set (CMAKE_VERBOSE_MAKEFILE TRUE) 

set (OpenGL_GL_PREFERENCE GLVND)
find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)

set (SOURCE_FILES
	src/main.cpp
	src/Template.cpp
)

add_executable (Project ${SOURCE_FILES})

target_include_directories (Project PUBLIC include)

include_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set (libs
	${OPENGL_LIBRARIES}
)

target_link_libraries (Project glfw ${libs})
