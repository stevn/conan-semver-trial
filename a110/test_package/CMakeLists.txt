cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(semver_a CONFIG REQUIRED)

add_executable(example src/example.cpp)
target_link_libraries(example semver_a::semver_a)
