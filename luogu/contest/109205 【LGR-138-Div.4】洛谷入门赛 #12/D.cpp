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
    i32 n;
    cin >> n;
    vector<vector<i32>> a;
    for (i32 i = 0; i < n; ++i)
    {
        i32 temp;
        cin >> temp;
        vector<i32> v;
        for (i32 j = 0; j < temp; ++j)
        {
            i32 t;
            cin >> t;
            v.emplace_back(t);
        }
        a.emplace_back(v);
    }
    unordered_set<i32> b{1};
    unordered_set<i32> c;
    for (auto &i : b)
    {
        for (auto &j : a[i - 1])
        {
            c.insert(j);
        }
    }
    swap(b, c);
    for (auto &i : b)
    {
        for (auto &j : a[i - 1])
        {
            c.insert(j);
        }
    }
    c.merge(b);
    cout << c.size();
    return 0;
}
