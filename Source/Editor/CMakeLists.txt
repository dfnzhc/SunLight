set(TARGET_NAME SLEditor)

file(GLOB_RECURSE SOURCE_FILES ./*.hpp ./*.cpp)
AssignSourceGroup(${SOURCE_FILES})

add_executable(${TARGET_NAME} ${SOURCE_FILES})

SetCompilerFlags(${TARGET_NAME})
SetDefaultCompileDefinitions(${TARGET_NAME})

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_23)

set_target_properties(${TARGET_NAME}
        PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY "${${SHORT_NAME}_BINARY_DIR}")
        

target_link_libraries(${TARGET_NAME}
        PUBLIC
        SL::SLLib
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
        
        PRIVATE
)
