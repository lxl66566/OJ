#include <iostream>
#include <vector>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using u64 = uint64_t;

i32 t, m, x, a, b;
i32 main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> m >> x >> a >> b;
        if (m >= x * b)
        {
            cout << 1 << endl;
            continue;
        }
        if (m < x)
        {
            a += m;
            cout << static_cast<f64>(a) / (a + b) << endl;
            continue;
        }
        auto maxn = m / x, aadd = m % x;
        f64 t1 = static_cast<f64>(a + m) / (a + b + m), t2 = static_cast<f64>(a + aadd) / (a + aadd + b - maxn);
        auto ans = max(t1, t2);
        i32 i = 0;
        do
        {
            i++;
            maxn--;
            auto tmp = max(static_cast<f64>(a + m - x * i) / (a + m - x * i + b - i),
                           static_cast<f64>(a + m - x * maxn) / (a + m - x * maxn + b - maxn));
            if (tmp <= ans)
                break;
            ans = tmp;
        } while (i < maxn);
        cout << ans << endl;
    }
    return 0;
}
