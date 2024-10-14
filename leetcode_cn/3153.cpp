#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

// using namespace absx;
using std::cin, std::cout, std::endl, std::vector, std::string, std::cerr;
typedef long long ll;

class Solution {
private:
  ll C(ll a, ll b) { return a > b ? 0 : a * (a + 1) / 2 * (b - a + 1) / 2; }
  ll calc(vector<int> const &nums) {
    ll ans = 0;
    ll cur = 0;
    for (auto const &x : nums) {
      if (x == 0) {
        continue;
      }
      ans += cur * x;
      cur += x;
    }
    return ans;
  }

public:
  long long sumDigitDifferences(vector<int> &nums) {
    auto s = vector<vector<int>>();
    while (1) {
      auto tmp = vector<int>(10, 0);
      for (auto &x : nums) {
        tmp[x % 10]++;
        x /= 10;
      }
      s.emplace_back(tmp);
      if (nums[0] == 0)
        break;
    }

    auto tmp = s | std::views::transform([&](auto &x) { return calc(x); });
    return std::accumulate(std::ranges::begin(tmp), std::ranges::end(tmp), 0ll,
                           std::plus<>());
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  std::vector<int> nums = {13, 23, 12};
  auto ret = Solution().sumDigitDifferences(nums);
  std::cout << ret << std::endl;

  std::vector<int> nums2 = {50, 28, 48};
  auto ret2 = Solution().sumDigitDifferences(nums2);

  std::cout << ret2 << std::endl;
  return 0;
}
