cmake_minimum_required(VERSION 2.8)

project(ImacGL)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include third-party/include)

if(UNIX)
    set(ALL_LIBRARIES glimac ${SDL2_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${GLUT_LIBRARY} ${GLU_LIBRARY})
endif(UNIX)

if(WIN32)
    MESSAGE(${GLEW_LIBRARY})
    set(ALL_LIBRARIES mingw32 glimac SDL2main SDL2 glew32s opengl32 glu32 freeglut) #add the libraries options in the LIB_LIST variable
endif(WIN32)

add_subdirectory(glimac)

#file(GLOB TP_DIRECTORIES "TP*")

#foreach(TP ${TP_DIRECTORIES})
    add_subdirectory(IMACMan)
#endforeach()
