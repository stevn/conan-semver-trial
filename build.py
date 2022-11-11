#!/usr/bin/env python3

"""Build the semver trials."""

import subprocess

for dir_name in ["a", "b", "a110", "super"]:
    cmd = [
        "conan",
        "create",
        dir_name,
        "-s:b",
        "build_type=Release",
    ]
    print("Running cmd: " + subprocess.list2cmdline(cmd))
    subprocess.check_call(cmd, universal_newlines=True)
