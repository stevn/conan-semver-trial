#pragma once

#ifdef _WIN32
  #define semver_a_EXPORT __declspec(dllexport)
#else
  #define semver_a_EXPORT
#endif

semver_a_EXPORT void semver_a();
