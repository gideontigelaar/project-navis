# CMake entry point
cmake_minimum_required (VERSION 3.1)
project (Navis)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# Compile external dependencies
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")

	# For leak-checking and profiling, add '-pg' to CXX flags
	# set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -O2")
	# valgrind --leak-check=full ./start
	# ./start # creates cmon.out
	# gprof start gmon.out > analysis.txt
endif(UNIX)

if(WIN32)
	# Create a group for Visual Studio
	SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

add_definitions( # g++ -Dxxx
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# Compile external dependencies
add_subdirectory (external)

include_directories( # g++ -Ipath/to/headerfiles
	external/glfw-3.3/include/
	external/glm-0.9.9.2/
	external/glew-1.9.0/include/
	.
)

link_directories( # g++ -Lpath/to/library

)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_190
)

# Common (libcommon.a)
add_library(common # ar rcs libcommon.a
	common/camera.cpp
	common/camera.h
	common/core.cpp
	common/core.h
	common/entity.cpp
	common/entity.h
	common/inputmanager.cpp
	common/inputmanager.h
	common/navisconfig.h
	common/renderer.cpp
	common/renderer.h
	common/resourcemanager.cpp
	common/resourcemanager.h
	common/scene.cpp
	common/scene.h
	common/sprite.cpp
	common/sprite.h
)

# Start
add_executable(start # g++ start/main.cpp -o start
	start/gamescene.cpp
	start/gamescene.h
	start/grasstile.cpp
	start/grasstile.h
	start/main.cpp
	start/tile.cpp
	start/tile.h
)
target_link_libraries(start # g++ -lcommon
	common
	${ALL_GRAPHICS_LIBS}
)
# Copy assets and shaders to the build directory
# (In Visual Studio, copy these directories to either 'Release' or 'Build')
file(
	COPY start/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY common/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)
