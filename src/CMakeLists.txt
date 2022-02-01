add_executable(test0 test.cc)
KyDepsPackageTarget(test0)

find_package(glog)
find_package(GTest)

add_test(NAME test0 COMMAND test0)
target_link_libraries(test0
    PRIVATE glog::glog
)
