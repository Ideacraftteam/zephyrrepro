set(FLUIDD_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "root directory")

cmake_minimum_required(VERSION 3.13.1)


list(INSERT OVERLAY_CONFIG 0 overlay-ot-defaults.conf)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE ZDebug)
endif()

# Point to the build type and common config files
set(CONF_FILE "prj.${CMAKE_BUILD_TYPE}.conf" "prj.common.conf")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

add_subdirectory(modules)

project(fluidd_firmware)

FILE(GLOB app_sources src/*.c)

target_sources(app PRIVATE ${app_sources})


#target_include_directories(app PRIVATE interface)
