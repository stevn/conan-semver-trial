#pragma once

#ifdef _WIN32
  #define semver_b_EXPORT __declspec(dllexport)
#else
  #define semver_b_EXPORT
#endif

semver_b_EXPORT void semver_b();
