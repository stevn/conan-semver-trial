# Conan semantic versioning trials

These files were created by running for example the following command (with conan client v1.54.0):

    conan new semver_a/1.0.0 --template=cmake_lib

The projects were then modified to represent the following dependency tree.

## Dependencies

    semver_a/1.0.0 -> semver_b/1.0.0 -> semver_super/1.0.0
    semver_a/1.1.0 --------------------------^

The package semver_a/1.0.0 is in subdirectory "a".
The package semver_a/1.1.0 is a copy of "a" in subdirectory "a110" with the version number "1.0.0" changed to "1.1.0".

## Build

Run the following commands to test if this dependency tree can be built with Conan.

Script:

    ./build.py

Manually:

    conan create a -s:b build_type=Release
    conan create b -s:b build_type=Release
    conan create a110 -s:b build_type=Release
    conan create super -s:b build_type=Release
