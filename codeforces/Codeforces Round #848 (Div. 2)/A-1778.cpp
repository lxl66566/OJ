#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,t;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int temp,ans = 0;
        bool flag = false,_2 = false,seen = false;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            ans += temp;
            if (_2) continue;
            if (temp == -1)
            {
                seen = true;
                if (flag)
                {
                    _2 = true;
                }
                else flag = true;
            }
            else flag = false;
        }
        if (_2) cout << ans + 4 << endl;
        else if (seen) cout << ans << endl;
        else cout << ans - 4 << endl;
    }
    
    return 0;
}