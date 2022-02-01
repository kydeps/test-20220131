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

add_subdirectory(src)
