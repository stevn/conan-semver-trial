cmake_minimum_required(VERSION 3.15)
project(semver_a CXX)

add_library(semver_a src/semver_a.cpp)
target_include_directories(semver_a PUBLIC include)

set_target_properties(semver_a PROPERTIES PUBLIC_HEADER "include/semver_a.h")
install(TARGETS semver_a)
