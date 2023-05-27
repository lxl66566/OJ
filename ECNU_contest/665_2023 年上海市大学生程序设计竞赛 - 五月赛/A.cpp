#include <iostream>
#include <vector>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u64 = uint64_t;

i32 main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int l = 1, r = n, ans = 1;
    while (l < r)
    {
        ++ans;
        r -= l;
        l <<= 1;
    }
    cout << ans;
    return 0;
}
