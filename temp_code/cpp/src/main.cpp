// #include "template.h"
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <ostream>
#include <queue>
// #include <ranges>
#include <string>
#include <vector>

// using namespace absx;
using std::cin, std::cout, std::endl, std::vector, std::string, std::cerr;
typedef long long ll;

auto solve(vector<int> s, int p) {
  auto collect = vector<int>(p, 0);
  for (auto &i : s) {
    i %= p;
    collect[i]++;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  return 0;
}
