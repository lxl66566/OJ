#include <bitset>
#include <functional>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using u64 = uint64_t;

using namespace std;
// using std::ranges;

// 260
class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        auto x    = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        auto mask = x & -x;
    }
};

i32 main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    return 0;
}