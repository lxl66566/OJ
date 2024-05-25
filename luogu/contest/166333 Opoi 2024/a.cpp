#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using i32 = int32_t;
using i64 = int64_t;
using f32 = float;
using f64 = double;
using u64 = uint64_t;
using usize = size_t;
using std::cin, std::cout, std::endl;

i64 N;
std::vector<i64> ans;

struct point {
  i64 x, y;
  f64 r2;
  i64 edges = 1;

  point(i64 x, i64 y) : x(x), y(y) { r2 = x * x + y * y; }
  f64 dist2(const point &other) const {
    return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
  }
  bool operator<(const point &other) const { return r2 > other.r2; }
  auto print() const {
    std::stringstream buffer;
    buffer << "point (" << x << ", " << y << ")";
    return buffer.str();
  }
};

std::vector<point> included;

point find_edge(point const &p) {
  auto minn = 1e16;
  auto ret = p;
  for (auto &q : included) {
    if (q.dist2(p) < minn) {
      minn = q.dist2(p);
      ret = q;
    }
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  cin >> N;
  included.reserve(N + 1);
  ans.reserve(N + 1);
  included.emplace_back(point{0, 0});
  ans.emplace_back(1);
  auto q = std::priority_queue<point>();
  i64 temp[2];
  for (i64 i = 0; i < N; i++) {
    cin >> temp[0] >> temp[1];
    q.push(point{temp[0], temp[1]});
  }

  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    auto nearest = find_edge(p);
    // std::cerr << "get point: " << p.print()
    //           << " , find nearest: " << nearest.print() << endl;
    p.edges = nearest.edges + 1;
    // std::cerr << "edge: " << p.edges << endl;
    included.push_back(p);
    ans.push_back(p.edges);
  }

  // assert_eq(ans.size(), N + 1);
  std::sort(ans.begin(), ans.end(), std::greater<i64>());
  auto sum = 0;
  for (auto &i : ans) {
    // std::cerr << i << " ";
    sum += i;
  }

  if (sum % 2 != 0) {
    cout << "No" << endl;
    return 0;
  }

  sum /= 2;

  for (auto &i : ans) {
    if (sum >= i) {
      sum -= i;
      if (sum == 0) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}