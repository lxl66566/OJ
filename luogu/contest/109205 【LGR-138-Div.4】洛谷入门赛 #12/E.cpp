#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u64 = uint64_t;

i32 main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    i32 n, t;
    cin >> n >> t;
    vector<i32> num(n);
    for (i32 i = 0; i < n; ++i)
        cin >> num[i];
    vector<i32> b(n), c(n);
    for (i32 i = 0; i < n; ++i)
    {
        b[i] = i;
    }
    while (t--)
    {
        c.clear();
        c.reserve(n);
        i32 k;
        cin >> k;
        for (i32 i = 0; i < k; ++i)
        {
            for (i32 j = i; j < n; j += k)
            {
                c.emplace_back(b[j]);
            }
        }
        swap(b, c);
        // cerr << "#  ";
        // for (i32 i = 0; i < n; ++i)
        // {
        //     cerr << b[i] << " ";
        // }
        // cerr << endl;
    }
    for (i32 i = 0; i < n; ++i)
    {
        cout << num[b[i]] << " ";
    }
    return 0;
}
