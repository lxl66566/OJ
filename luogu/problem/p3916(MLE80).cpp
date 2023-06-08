#include <iostream>
#include <vector>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using u64 = uint64_t;

vector<i32> result{ 0 };
vector<vector<i32>> e;

void dp(i32 now, i32 i) {
    if (result[now] != now || i < now) return;
    result[now] = i;
    for (auto const &x : e[now]) {
        dp(x, i);
    }
}
i32 main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    i32 n, m;
    cin >> n >> m;
    result.resize(n + 1);
    e.resize(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        result[i] = i;
    }
    for (i32 i = 1; i <= m; ++i) {
        i32 a, b;
        cin >> a >> b;
        e[b].emplace_back(a);
    }
    for (i32 i = n; i >= 1; --i) {
        dp(i, i);
    }
    for (i32 i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
    return 0;
}