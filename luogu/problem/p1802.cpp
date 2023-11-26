#include "template.h"

using namespace absx;
using std::cin, std::cout, std::endl, std::cerr;

struct item {
  i32 profit;
  i32 cost;
  bool operator<(const item &other) const { return cost < other.cost; }
};
// 01 背包忘了，结果内外层循环弄反了。
i32 main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  i32 n, x, minn = INT_MAX, sum = 0;
  cin >> n >> x;
  std::vector<i32> f(x + 1);
  std::vector<item> items;
  items.reserve(n);
  for (i32 i = 0; i < n; i++) {
    i32 tmp1, tmp2, tmp3;
    cin >> tmp1 >> tmp2 >> tmp3;
    sum += tmp1;
    items.emplace_back(item{tmp2 - tmp1, tmp3});
    minn = std::min(minn, tmp3);
  }
  for (auto &item : items) {
    for (i32 i = x; i >= minn; i--) {
      if (i < item.cost)
        break;
      f[i] = std::max(f[i], f[i - item.cost] + item.profit);
    }
  }
  cout << static_cast<i64>(sum + f[x]) * 5ll << endl;

  return 0;
}