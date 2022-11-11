#pragma once

#ifdef _WIN32
  #define semver_super_EXPORT __declspec(dllexport)
#else
  #define semver_super_EXPORT
#endif

semver_super_EXPORT void semver_super();
