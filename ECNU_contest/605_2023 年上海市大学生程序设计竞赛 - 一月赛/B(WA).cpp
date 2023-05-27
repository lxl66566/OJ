#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long ll;
int t,n;
// void test()
// {
//     freopen("test.txt","w",stdout);
//     for (int i = 1; i <= 1e3; i++)
//     {
//         unordered_set<int> se;
//         int ans = 0;
//         for (int j = i; j >= 1;--j)
//         {
//             if (!se.count(j + 5) && !se.count(j + 8)) {++ ans;se.insert(j);}
//         }
//         cout << ans << ",";
//     }
// }
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // test();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << n / 13 * 5 + (n % 13 < 5 ? n % 13 : 5) << endl;
    }
    return 0;
}