# Conan Semantic Versioning Trials

It seems that there is a problem with the Semantic Versioning (<https://semver.org/>) concept in Conan (<https://conan.io/>). This repository shall be used for testing of this concept.

## Setup

These files were created by running for example the following command (with Conan client v1.54.0) to create some projects for testing:

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

## Failure

With conan client v1.54.0 the build of the semver_super package fails:

    WARN: semver_b/1.0.0: requirement semver_a/[~1.0.0] overridden by semver_super/1.0.0 to semver_a/1.1.0
    ERROR: Version range '~1.0.0' required by 'semver_b/1.0.0' not valid for downstream requirement 'semver_a/1.1.0'

## Semantic versioning with version ranges

Version ranges are documented at:

<https://docs.conan.io/en/latest/versioning/version_ranges.html>

We use the default versioning schema (semver_direct_mode) for these tests. Read more here:

<https://docs.conan.io/en/latest/creating_packages/define_abi_compatibility.html>

## Problem

The problem seems to be that the version range which uses the tilde sign for semantic versioning (e.g. `[~1.0.0]`) is triggering additional checks of the compatibility of the dependencies.

Related issues seem to exist:

- <https://github.com/conan-io/conan/issues/5507>
- <https://github.com/conan-io/conan/pull/5713>
- <https://github.com/conan-io/conan/issues/11106>

## Workaround

When replacing the tilde sign with greater-equals / less-than signs, the build succeeds.

### Patch 1

In "b/conanfile.py", replace:

    self.requires("semver_a/[~1.0.0]")

...with:

    self.requires("semver_a/[>=1.0.0 <2]")

### Patch 2

In "super/conanfile.py", replace:

    self.requires("semver_a/[~1.1.0]")
    self.requires("semver_b/[~1.0.0]")

...with:

    self.requires("semver_a/[>=1.1.0 <2]")
    self.requires("semver_b/[>=1.0.0 <2]")

### Branch

See branch `workaround` where these patches have been applied.

## Conclusion

The behavior of Conan seems inconsistent in this case. The version range using tilde sign should probably behave like this workaround does.
