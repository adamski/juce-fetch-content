cmake_minimum_required(VERSION 3.21)
project(JuceFetchContent)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent

set(FETCHCONTENT_QUIET FALSE)

# Add all JUCE module sources so they are browsable in exported IDE projects
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)

FetchContent_Declare(
        juce
        GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(juce)

set(SOURCES_MAIN
        library.cpp
        )

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Source" FILES ${SOURCES_MAIN})

message(${juce_SOURCE_DIR})

file(GLOB_RECURSE JUCE_MODULE_SOURCES
        "${juce_SOURCE_DIR}/modules/*"

source_group(TREE ${juce_SOURCE_DIR}/modules PREFIX "Modules" FILES ${JUCE_MODULE_SOURCES})

add_library(JuceFetchContent STATIC ${SOURCES_MAIN})

target_compile_definitions(JuceFetchContent PUBLIC
        JUCE_STANDALONE_APPLICATION=0
        )

target_link_libraries(JuceFetchContent
        PRIVATE
        # BinaryData            # If we'd created a binary data target, we'd link to it here
        juce::juce_audio_utils
        juce::juce_audio_formats
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
