cmake_minimum_required(VERSION 3.20)
project(glaze_sample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  glaze
  GIT_REPOSITORY https://github.com/stephenberry/glaze.git
  GIT_TAG main
)
FetchContent_MakeAvailable(glaze)

add_executable(glaze_sample main.cpp)
target_link_libraries(glaze_sample PRIVATE glaze::glaze)
