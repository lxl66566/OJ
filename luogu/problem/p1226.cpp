#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
auto power(i64 a, i64 b, i64 mod) -> i64 {
    i64 res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
i32 main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<i64> a(3);
    for (i32 i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    cout << a[0] << "^" << a[1] << " mod " << a[2] << "=" << power(a[0],a[1],a[2]) << endl;
    return 0;
}