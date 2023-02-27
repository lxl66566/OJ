#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = int64_t;
using i32 = int32_t;
unsigned __int128 a;
i32 t;
i32 main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    a--;
    while(a)
    {
    	i32 temp = a % 10;
    	cout << temp;
    	a /= 10;
	}
    return 0;
}
