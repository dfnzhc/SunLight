set(TARGET_NAME SLLib)

file(GLOB_RECURSE SOURCE_FILES ./*.hpp ./*.cpp)
AssignSourceGroup(${SOURCE_FILES})

add_library(${TARGET_NAME} SHARED ${SOURCE_FILES})

SetCompilerFlags(${TARGET_NAME})
SetDefaultCompileDefinitions(${TARGET_NAME})

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_23)

set_target_properties(${TARGET_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${${SHORT_NAME}_BINARY_DIR}")

add_library(SL::${TARGET_NAME} ALIAS ${TARGET_NAME})

find_package(fmt CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(magic_enum CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)
find_path(STRINGZILLA_INCLUDE_DIRS "stringzilla/drafts.h")

target_link_libraries(${TARGET_NAME}
        PUBLIC
        fmt::fmt
        glm::glm-header-only
        magic_enum::magic_enum
        SDL3::SDL3
        PRIVATE
)

target_compile_options(${TARGET_NAME}
        PUBLIC

        # MSVC
        $<$<CXX_COMPILER_ID:MSVC>:/DEBUG /Zc:preprocessor>
)

target_compile_definitions(${TARGET_NAME}
        PUBLIC
        "$<$<CONFIG:Debug,RelWithDebInfo>:BEE_ENABLE_DEBUG>"
)

target_include_directories(${TARGET_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${STRINGZILLA_INCLUDE_DIRS}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/SL
)

target_precompile_headers(${TARGET_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/SL/Defines.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/SL/Math.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/SL/ThirdParty.hpp
)