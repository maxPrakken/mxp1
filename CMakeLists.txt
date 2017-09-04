# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (MXP1)

find_package(OpenGL REQUIRED)


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
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-1c73e35")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
    add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)

include_directories(
    external/glfw-3.0.3/include/GLFW/
    external/glm-0.9.7.0/
    external/glew-1.9.0/include/
	mxp1/
    .
)

set(ALL_LIBS
    ${OPENGL_LIBRARY}
    GLFW_303
    GLEW_190
	mxp1
)

add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

# mxp1 libary
add_library(mxp1	
	mxp1/shader.h
    mxp1/shader.cpp
    mxp1/camera.h
    mxp1/camera.cpp
    mxp1/texture.h
    mxp1/texture.cpp
    mxp1/renderer.h
    mxp1/renderer.cpp
    mxp1/sprite.h
    mxp1/sprite.cpp
    mxp1/scene.cpp
    mxp1/scene.h
    mxp1/vector2.cpp
    mxp1/vector2.h
    mxp1/print.cpp
    mxp1/print.h
    mxp1/entity.cpp
    mxp1/entity.h
    mxp1/core.cpp
    mxp1/core.h
    mxp1/input.cpp
    mxp1/input.h
)

# game
add_executable(game
	game/main.cpp
	game/myScene.cpp
	game/myScene.h
)

# Demo
add_executable(demo
    demo/demo.cpp
)
target_link_libraries(demo
    ${ALL_LIBS}
)

target_link_libraries(game
	${ALL_LIBS}
)

# Xcode and Visual working directories
set_target_properties(demo PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/demo/")
create_target_launcher(demo WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/demo/")


SOURCE_GROUP(mxp1 REGULAR_EXPRESSION ".*/mxp1/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )


if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
#add_custom_command(
#   TARGET demo POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/demo${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/demo/"
#)
elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )


# Copy assets to the build directory
file(
    COPY demo/assets
    DESTINATION ${CMAKE_BINARY_DIR}
)
file(
    COPY demo/shaders
    DESTINATION ${CMAKE_BINARY_DIR}
)