cmake_minimum_required(VERSION 3.24)

option(SUPERBUILD "Perform a superbuild (or not)" OFF)

project(sdl-bgfx-imgui-starter LANGUAGES CXX)

set(THIRD_PARTY_BUILD_DIR_NAME build)
if (SUPERBUILD)
    include(third-party/CMakeLists.txt)
    include(cmake/superbuild.cmake)
    return()
endif ()

find_package(SDL2 REQUIRED CONFIG CMAKE_FIND_ROOT_PATH_BOTH)
find_package(SDL2_image REQUIRED CONFIG CMAKE_FIND_ROOT_PATH_BOTH)
find_package(bgfx REQUIRED CONFIG CMAKE_FIND_ROOT_PATH_BOTH)
find_package(imgui.cmake REQUIRED CONFIG CMAKE_FIND_ROOT_PATH_BOTH)

add_executable(${PROJECT_NAME}
        src/graphics/texture.cpp
        src/graphics/texture.h
        src/graphics/structs/pos_tex_vertex.cpp
        src/graphics/structs/pos_tex_vertex.h
        src/graphics/rendering/shaders.cpp
        src/graphics/rendering/shaders.h
        src/graphics/utils/colors.cpp
        src/graphics/utils/colors.h
        src/world/chunk.cpp
        src/world/chunk.h
        src/graphics/structs/cube.cpp
        src/graphics/structs/cube.h
        src/math/vector_3.cpp
        src/math/vector_3.h
        src/graphics/rendering/render_batch.cpp
        src/graphics/rendering/render_batch.h
        src/game/player.cpp
        src/game/player.h
        src/game/structs/camera.cpp
        src/game/structs/camera.h
        src/game/game_context.cpp
        src/game/game_context.h
)
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp
        sdl-imgui/imgui_impl_sdl2.cpp
        bgfx-imgui/imgui_impl_bgfx.cpp
)
target_compile_features(
        ${PROJECT_NAME} PRIVATE cxx_std_11
)
target_include_directories(
        ${PROJECT_NAME} PRIVATE SDL2_Image
)

target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        SDL2::SDL2-static
        SDL2::SDL2main
        SDL2_image::SDL2_image-static
        bgfx::bgfx
        bgfx::bx
        imgui.cmake::imgui.cmake
)

target_link_options(
        ${PROJECT_NAME} PRIVATE $<$<BOOL:${EMSCRIPTEN}>:-sMAX_WEBGL_VERSION=2
        -sALLOW_MEMORY_GROWTH=1 --preload-file=shader/embuild/v_simple.bin
        --preload-file=shader/embuild/f_simple.bin>)
target_compile_definitions(
        ${PROJECT_NAME} PRIVATE $<$<BOOL:${EMSCRIPTEN}>:USE_SDL=2>)


add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/shader/build
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/shader/build
        VERBATIM
)

set_target_properties(
        ${PROJECT_NAME}
        # required for project when using visual studio generator
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>)

add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
        VERBATIM
)
