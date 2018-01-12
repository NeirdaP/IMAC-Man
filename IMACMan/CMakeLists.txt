file(GLOB HEADER_FILES *.hpp)
file(GLOB SRC_FILES *.cpp)
file(GLOB_RECURSE SHADER_FILES *.glsl)

foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(FILE ${SRC_FILE} NAME_WE)
    get_filename_component(DIR . NAME)
    set(OUTPUT ${DIR}_${FILE})
    add_executable(${OUTPUT} ${SRC_FILE} ${HEADER_FILES} ${SHADER_FILES} ../glimac/include/glimac/FreeFlyCamera.hpp src/Personnage.cpp include/Personnage.h src/Pacman.cpp include/Pacman.h src/Ghost.cpp include/Ghost.h src/Board.cpp include/Board.h src/Labyrinth.cpp include/Labyrinth.h src/GameApp.cpp include/GameApp.h src/OpenGLHandler.cpp include/OpenGLHandler.hpp src/IndexBuffer.cpp include/IndexBuffer.hpp src/Renderer.cpp include/Renderer.hpp src/VertexBuffer.cpp include/VertexBuffer.hpp src/VertexArrayBuffer.cpp include/VertexArrayBuffer.hpp src/Model.cpp include/Model.hpp src/Case.cpp include/Case.hpp src/Sphere.cpp include/Sphere.hpp src/Camera.cpp include/Camera.hpp)
    target_link_libraries(${OUTPUT} ${ALL_LIBRARIES})
endforeach()

file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
