#pragma once
#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

namespace absx {
using i32 = int32_t;
using i64 = int64_t;
using f32 = float;
using f64 = double;
using u64 = uint64_t;
using usize = size_t;
float Q_rsqrt(float number) {
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y = number;
  i = *(long *)&y;           // evil floating point bit level hacking
  i = 0x5f3759df - (i >> 1); // what the fuck?
  y = *(float *)&i;
  y = y * (threehalfs - (x2 * y * y)); // 1st iteration
  // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be
  // removed

  return y;
}
} // namespace absx

#define assert_eq(expected, actual)                                            \
  do {                                                                         \
    if ((expected) != (actual)) {                                              \
      std::cerr << "Assertion failed: " << #expected << " == " << #actual      \
                << " in " << __FILE__ << " line " << __LINE__ << std::endl;    \
      std::cerr << "Expected: " << (expected) << ", actual: " << (actual)      \
                << std::endl;                                                  \
      std::abort();                                                            \
    }                                                                          \
  } while (0)
