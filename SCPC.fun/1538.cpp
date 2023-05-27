/*
http://scpc.fun/problem/1538
*/
#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
i32 l,r;
i32 change_first_0_from_right(i32 &a)
{
    for(i32 i = 0;i < 31;++i)
    {
        if(!((1 << i) & a))
        {
            a ^= (1 << i);
            return a;
        }
    }
    return -1;
}
i32 main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> l >> r;
    if (((r + 1) ^ (1 << __builtin_ctz(r + 1))) == 0 || l == r)
    {
        cout << r;
        return 0;
    }
    i32 r2 = (1 << (31 - __builtin_clz(r))) - 1;
    if (r2 >= l){
        cout << r2;
        return 0;
    }
    i32 ans;
    do{
        ans = l;
    }while (change_first_0_from_right(l) <= r);
    cout << ans;
    return 0;
}
