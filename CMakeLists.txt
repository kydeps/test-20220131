cmake_minimum_required(VERSION 3.22)
project(hello_world VERSION 0.1)

set(KYDEPS_BOILERPLATE_CLANG_TIDY OFF)
include(FetchContent)
FetchContent_Declare(
    kydeps_boilerplate
    GIT_REPOSITORY https://github.com/kydeps/boilerplate.git
    GIT_TAG main)
FetchContent_MakeAvailable(kydeps_boilerplate)
KyDepsAddBoilerplate()

set(CMAKE_CXX_STANDARD 20)

set(KYDEPS_TARGETS glog GTest)

include(FetchContent)
FetchContent_Declare(
    kydeps_definitions
    GIT_REPOSITORY https://github.com/kydeps/definitions.git
    GIT_TAG 3f21d17691eb5b271bd7a72fb26ca962d28c73c8 # main as of 20220129
)
FetchContent_MakeAvailable(kydeps_definitions)

add_subdirectory(src)
