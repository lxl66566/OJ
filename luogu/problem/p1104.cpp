#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u64 = uint64_t;
struct p
{
    string name;
    i32 y, m, d, n;
};

i32 main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    i32 n;
    cin >> n;
    vector<p> a;
    for (i32 i = 0; i < n; i++)
    {
        p temp;
        cin >> temp.name >> temp.y >> temp.m >> temp.d;
        temp.n = i;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), [](const p &a, const p &b) -> bool
         {
            if(a.y != b.y) return a.y < b.y;
            if(a.m != b.m) return a.m < b.m;
            if(a.d != b.d)return a.d < b.d; 
            return a.n > b.n; });
    for (auto i : a)
    {
        cout << i.name << endl;
    }
    return 0;
}
