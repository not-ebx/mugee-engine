cmake_minimum_required(VERSION 3.24)

if (NOT SUPERBUILD)
    project(third-party)
endif ()

include(ExternalProject)

get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if (NOT isMultiConfig)
    if (NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE
                Debug
                CACHE STRING "" FORCE)
    endif ()
    set(build_type_dir ${CMAKE_BUILD_TYPE})
    set(build_type_arg -DCMAKE_BUILD_TYPE=$<CONFIG>)
else ()
    set(build_config_arg --config=$<CONFIG>)
endif ()

if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
    set(THIRD_PARTY_CMAKE_COMMAND emcmake cmake)
else ()
    set(THIRD_PARTY_CMAKE_COMMAND ${CMAKE_COMMAND})
endif ()

if (SUPERBUILD)
    set(PREFIX_DIR
            ${CMAKE_CURRENT_SOURCE_DIR}/third-party/${THIRD_PARTY_BUILD_DIR_NAME})
else ()
    set(PREFIX_DIR ${CMAKE_CURRENT_BINARY_DIR})
endif ()

ExternalProject_Add(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.28.4
        PREFIX ${PREFIX_DIR}
        BINARY_DIR ${PREFIX_DIR}/src/SDL2-build/${build_type_dir}
        CMAKE_COMMAND ${THIRD_PARTY_CMAKE_COMMAND}
        CMAKE_ARGS ${build_type_arg} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
        BUILD_COMMAND cmake --build <BINARY_DIR> ${build_config_arg}
        INSTALL_COMMAND cmake --build <BINARY_DIR> --target install
        ${build_config_arg})

ExternalProject_Add(
        bgfx
        GIT_REPOSITORY https://github.com/pr0g/bgfx.cmake.git
        GIT_TAG bde3f94ce75ffd184e9a3bdfe947a3bec69233eb
        PREFIX ${PREFIX_DIR}
        BINARY_DIR ${PREFIX_DIR}/src/bgfx-build/${build_type_dir}
        CMAKE_COMMAND ${THIRD_PARTY_CMAKE_COMMAND}
        CMAKE_ARGS ${build_type_arg}
        -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
        "$<$<CONFIG:Debug>:-DCMAKE_DEBUG_POSTFIX=d>"
        "$<$<PLATFORM_ID:Emscripten>:-DBGFX_CONFIG_MULTITHREADED=OFF>"
        -DBGFX_BUILD_EXAMPLES=OFF
        BUILD_COMMAND cmake --build <BINARY_DIR> ${build_config_arg}
        INSTALL_COMMAND cmake --build <BINARY_DIR> --target install
        ${build_config_arg})

ExternalProject_Add(
        imgui.cmake
        GIT_REPOSITORY https://github.com/pr0g/imgui.cmake.git
        GIT_TAG 20e7d1a627690526c98b0b48c346e384ab87c5a6
        PREFIX ${PREFIX_DIR}
        BINARY_DIR ${PREFIX_DIR}/src/imgui.cmake-build/${build_type_dir}
        CMAKE_COMMAND ${THIRD_PARTY_CMAKE_COMMAND}
        CMAKE_ARGS ${build_type_arg} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
        "$<$<CONFIG:Debug>:-DCMAKE_DEBUG_POSTFIX=d>"
        -DIMGUI_DISABLE_OBSOLETE_FUNCTIONS=ON
        BUILD_COMMAND cmake --build <BINARY_DIR> ${build_config_arg}
        INSTALL_COMMAND cmake --build <BINARY_DIR> --target install
        ${build_config_arg})

ExternalProject_Add(
        SDL2_Image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG release-2.8.2
        PREFIX ${PREFIX_DIR}
        BINARY_DIR ${PREFIX_DIR}/src/SDL2_Image-build/${build_type_dir}
        CMAKE_COMMAND ${THIRD_PARTY_CMAKE_COMMAND}
        CMAKE_ARGS ${build_type_arg} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
        BUILD_COMMAND cmake --build <BINARY_DIR> ${build_config_arg}
        INSTALL_COMMAND cmake --build <BINARY_DIR> --target install
        ${build_config_arg}
)

ExternalProject_Add(
        OctoMap
        GIT_REPOSITORY https://github.com/OctoMap/octomap.git
        GIT_TAG v1.9.5
        PREFIX ${PREFIX_DIR}
        SOURCE_DIR ${PREFIX_DIR}/src/OctoMap          # Adding SOURCE_DIR
        BINARY_DIR ${PREFIX_DIR}/src/OctoMap-build    # Removed /${build_type_dir}
        CMAKE_COMMAND ${THIRD_PARTY_CMAKE_COMMAND}
        CMAKE_ARGS ${build_type_arg} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DBUILD_OCTOVIS_SUBPROJECT=OFF -DBUILD_DYNAMICETD3D_SUBPROJECT=OFF
        BUILD_COMMAND cmake --build <BINARY_DIR> ${build_config_arg}
        INSTALL_COMMAND cmake --build <BINARY_DIR> --target install
        ${build_config_arg}
)