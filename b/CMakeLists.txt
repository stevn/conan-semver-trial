cmake_minimum_required(VERSION 3.15)
project(semver_b CXX)

find_package(semver_a REQUIRED)

add_library(semver_b src/semver_b.cpp)
target_include_directories(semver_b PUBLIC include)
target_link_libraries(semver_b PRIVATE semver_a::semver_a)

set_target_properties(semver_b PROPERTIES PUBLIC_HEADER "include/semver_b.h")
install(TARGETS semver_b)
