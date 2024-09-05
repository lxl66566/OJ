// #include "template.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <unordered_set>
#include <vector>

// using namespace absx;
using std::cin, std::cout, std::endl, std::vector, std::string, std::cerr;

// 这题思路就错了，我看了提示是贪心，思路就完全变成贪心了：每次从里面拿一个让总价值增加最大的元素。但是这是错误的。

namespace std {
template <> struct hash<std::vector<int>> {
  size_t operator()(const std::vector<int> &p) const noexcept {
    auto hash1 = std::hash<int>{}(p[0]);
    auto hash2 = std::hash<int>{}(p[1]);
    return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
  }
};
} // namespace std

class Solution {
public:
  long long findMaximumElegance(vector<vector<int>> &items, int k) {
    auto set = std::unordered_multiset<vector<int>>(items.begin(), items.end());
    long long ans = 0;
    auto used_cat = std::unordered_set<int>(k);
    while (k--) {
      auto maxn = 0;
      auto record = std::vector<int>(2);
      for (auto &i : set) {
        auto profit = i[0];
        auto temp = !used_cat.contains(i[1]) ? (used_cat.size() * 2 + 1) : -1;
        if (temp != -1) {
          profit += temp;
        }
        if (profit > maxn) {
          maxn = profit;
          record = i;
        }
      }
      ans += maxn;
      used_cat.insert(record[1]);
      auto it = set.find(record);
      // assert(it != set.end());
      cerr << maxn << " " << record[0] << " " << record[1] << endl;
      set.erase(it);
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  auto solution = Solution();
  // auto input1 = std::vector<std::vector<int>>{
  //     {3, 2},
  //     {5, 1},
  //     {10, 1},
  // };
  // cout << solution.findMaximumElegance(input1, 2) << endl;
  // auto input2 = std::vector<std::vector<int>>{
  //     {3, 1},
  //     {3, 1},
  //     {2, 2},
  //     {5, 3},
  // };
  // cout << solution.findMaximumElegance(input2, 3) << endl;
  // auto input3 = std::vector<std::vector<int>>{
  //     {2, 2},
  //     {2, 2},
  // };
  auto input3 = std::vector<std::vector<int>>{
      {{2, 2}, {8, 6}, {10, 6}, {2, 4}, {9, 5}, {4, 5}}};
  cout << solution.findMaximumElegance(input3, 4) << endl;

  return 0;
}
