#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u64 = uint64_t;
u64 f(u64 a)
{
    u64 ans = 1;
    if (a == 0)
        return 2;
    for (a--; a > 0 && a < 50; a -= 2)
        ans *= a;
    return ans * 2;
}
i32 main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    i32 t;
    cin >> t;
    while (t--)
    {
        u64 n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}
