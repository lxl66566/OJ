#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u64 = uint64_t;
i64 ans = 0;
i32 solve(i32 x1, i32 y1, i32 x2, i32 y2)
{
    if(x1 == x2)
    {
        return abs(y1 - y2);
    }
    if(y1 == y2)
    {
        return abs(x1 - x2);
    }
    return -1;
}
inline i32 sgn(i32 x)
{
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}
i32 main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    i32 x1,x2,y1,y2; 
    cin >> x1 >> y1 >> x2 >> y2;
    if((abs(x1 - x2) + abs(y1 - y2)) % 2 != 0)
    {
        cout << -1;
        return 0;
    }
    auto temp = solve(x1,y1,x2,y2);
    if(temp != -1)
    {
        cout << temp;
        return 0;
    }
    i32 far = 0;
    if((x1 > x2 && y1 < y2) || (x1 < x2 && y1 > y2))
        far = 1;
    else far = -1;
    if(abs(x1 - x2) < abs(y1 - y2))
    {
        ans += abs(x1 - x2) * 2 + (abs(x1 - x2) % 2 != 0 ? far : 0);
        y2 += abs(x2 - x1) * sgn(y1 - y2);
        ans += abs(y1 - y2);
    }   
    else
    {
        ans += abs(y1 - y2) * 2 + (abs(y1 - y2) % 2 != 0 ? far : 0);
        x2 += abs(y2 - y1) * sgn(x1 - x2);
        ans += abs(x1 - x2);
    }
   cout << ans;
    return 0;
}
