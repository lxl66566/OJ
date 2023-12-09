#include "template.h"
#include <algorithm>

using namespace absx;
using std::vector;
// 手写了二分查找，然后发现题解 upper_bound / lower_bound 可以传 lambda
// 比较函数。
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    i32 l = 0, r = matrix.size() - 1, line = -1;
    while (l <= r) {
      i32 mid = (l + r) / 2;
      if (matrix[mid][0] <= target &&
          (mid == r || matrix[mid + 1][0] > target)) {
        if (matrix[mid][0] == target) {
          return true;
        }
        line = mid;
        break;
      } else if (matrix[mid][0] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    if (line == -1)
      return false;
    auto i = lower_bound(matrix[line].begin(), matrix[line].end(), target);
    return i != matrix[line].end() && *i == target;
  }
};

i32 main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  std::cout << Solution().searchMatrix(matrix, 13) << std::endl;
  return 0;
}