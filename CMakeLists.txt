cmake_minimum_required(VERSION 3.24)

option(SUPERBUILD "Perform a superbuild (or not)" OFF)
project(funnygemu LANGUAGES CXX)

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
find_package(OctoMap REQUIRED CONFIG CMAKE_FIND_ROOT_PATH_BOTH)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/game/game_state_manager.cpp
        src/game/game_state_manager.h
        src/game/context/render_context.cpp
        src/game/context/render_context.h
        src/game/context/player_context.cpp
        src/game/context/player_context.h
        src/game/state/abstract/game_state.cpp
        src/game/state/abstract/game_state.h
        src/graphics/objects/block_3_d.cpp
        src/graphics/objects/block_3_d.h
        src/graphics/utils/helper.cpp
        src/graphics/utils/helper.h
        src/graphics/structs/pos_tex_vertex.cpp
        src/game/state/setup_state.cpp
        src/game/state/playable_state.cpp
        src/graphics/utils/colors.cpp
        src/graphics/texture.cpp
        src/world/player.cpp
        src/world/structs/camera.cpp
        src/world/objects/object_factory.cpp
        src/world/objects/object_factory.h
        src/world/spatial_partitioning/voxel_grid.cpp
        src/world/spatial_partitioning/voxel_grid.h
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
        SDL2_image::SDL2_image
        bgfx::bgfx
        bgfx::bx
        bgfx::bimg
        imgui.cmake::imgui.cmake
        octomap-static
        octomath-static
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