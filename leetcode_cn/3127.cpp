// #include "template.h"
#include <iostream>
#include <vector>

// using namespace absx;
using std::cin, std::cout, std::endl, std::vector;

bool two_two(const std::vector<char> &v) {
  auto a = 0, b = 0;
  for (auto &i : v) {
    if (i == 'B') {
      a++;
    } else if (i == 'W') {
      b++;
    }
  }
  return a == b;
}
class Solution {
public:
  bool canMakeSquare(vector<vector<char>> &grid) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (!two_two({grid[i][j], grid[i + 1][j], grid[i][j + 1],
                      grid[i + 1][j + 1]})) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::vector<std::vector<char>> grid = {
      {'B', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'B'}};
  cout << Solution().canMakeSquare(grid) << endl;
  return 0;
}