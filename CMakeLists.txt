cmake_minimum_required(VERSION 3.31)
project(demo_library C CXX)

include(CTest)
include(FetchContent)

FetchContent_Declare(fetch_github_content GIT_REPOSITORY https://github.com/CesarBerriot/fetch_github_content.git GIT_TAG 1.0.0)
FetchContent_MakeAvailable(fetch_github_content)
include(${fetch_github_content_SOURCE_DIR}/fetch_github_content.cmake)

fetch_github_content(
  setup_gtest CesarBerriot 1.2.0 INCLUDE_DEFAULT
  discover_sources CesarBerriot 1.0.0 INCLUDE_DEFAULT
)

add_library(demo_library)
target_include_directories(demo_library PUBLIC include PRIVATE source)
discover_sources(demo_library)
if(${BUILD_TESTING})
  setup_gtest(demo_library)
endif()