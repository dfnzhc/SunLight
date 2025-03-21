cmake_minimum_required(VERSION 3.7...3.27)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake)

set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# --------------------------------------------------------------
# Project Configuration
# --------------------------------------------------------------
project(SunLight
    LANGUAGES CXX C)

set(SHORT_NAME SL)
string(TOLOWER ${SHORT_NAME} SHORT_NAME_LOWER)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

# Platform
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(${SHORT_NAME}_PLATFORM "Windows")
    set(${SHORT_NAME}_IN_WINDOWS TRUE)
else()
    # ...
endif()

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# --------------------------------------------------------------
# Global settings
# --------------------------------------------------------------
set(${SHORT_NAME}_BUILD_TESTS ON CACHE BOOL "Build test programs")

set(${SHORT_NAME}_BINARY_DIR ${CMAKE_SOURCE_DIR}/Bin)

if(CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release;MinSizeRel;RelWithDebInfo" CACHE STRING "" FORCE)
else()
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY HELPSTRING "Choose the type of build")
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug;Release;MinSizeRel;RelWithDebInfo")
endif()

if(CMAKE_CONFIGURATION_TYPES)
    set(${SHORT_NAME}_OUTPUT_DIR ${${SHORT_NAME}_RUNTIME_OUTPUT_DIR}/$<CONFIG>)
else()
    set(${SHORT_NAME}_OUTPUT_DIR ${${SHORT_NAME}_RUNTIME_OUTPUT_DIR})
endif()

if(WIN32)
    if(MSVC)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
    endif()

    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${SHORT_NAME}_BINARY_DIR}/Libs)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${SHORT_NAME}_BINARY_DIR}/Libs)
endif()

include(HelperFunctions)

# --------------------------------------------------------------
# Sources
# --------------------------------------------------------------

# #####################################
# Extern libraries
add_subdirectory(External)

# #####################################
# Project
add_subdirectory(Source)

# #####################################
# Tests
if(${SHORT_NAME}_BUILD_TESTS)
    enable_testing()
    add_subdirectory(Tests)
endif()