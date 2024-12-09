cmake_minimum_required(VERSION 3.16)

project(SnakeSFML LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraires" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(SOURCE_FILES

    "src/main.cpp"

    "src/Apple.cpp"
    "src/headers/Apple.h"

    "src/Game.cpp"
    "src/headers/Game.h"

    "src/Body.cpp"
    "src/headers/Body.h"

    "src/SnakeHead.cpp"
    "src/headers/SnakeHead.h"

)

add_executable(SnakeSFML ${SOURCE_FILES})
target_link_libraries(SnakeSFML PRIVATE sfml-graphics)
target_compile_features(SnakeSFML PRIVATE cxx_std_17)

# add all files wich must be copyied in build dir
set(COPY_FILES
    "${CMAKE_SOURCE_DIR}/src/textures/apple.png"
    "${CMAKE_SOURCE_DIR}/src/textures/snake-graphics.png"
    "${CMAKE_SOURCE_DIR}/src/textures/snake_body.png"
    "${CMAKE_SOURCE_DIR}/src/textures/snake_head.png"
)


# Copy font file to build dir
add_custom_command(TARGET SnakeSFML POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:SnakeSFML>/textures
    COMMAND ${CMAKE_COMMAND} -E copy ${COPY_FILES} $<TARGET_FILE_DIR:SnakeSFML>/textures
    COMMENT "Copying files to output directory"
)


if(WIN32)
    add_custom_command(
        TARGET SnakeSFML
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SnakeSFML>
        VERBATIM)
endif()