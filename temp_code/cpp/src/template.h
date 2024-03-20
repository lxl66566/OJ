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
using f64 = double;
using u64 = uint64_t;
using usize = size_t;
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