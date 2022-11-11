cmake_minimum_required(VERSION 3.15)
project(semver_super CXX)

find_package(semver_a REQUIRED)
find_package(semver_b REQUIRED)

add_library(semver_super src/semver_super.cpp)
target_include_directories(semver_super PUBLIC include)
target_link_libraries(semver_super PRIVATE semver_a::semver_a)
target_link_libraries(semver_super PRIVATE semver_b::semver_b)

set_target_properties(semver_super PROPERTIES PUBLIC_HEADER "include/semver_super.h")
install(TARGETS semver_super)
