#include <iostream>
#define ll long long
using namespace std;
int a[20000] = {1},n;
ll ans,t,k;
void init()
{
    int temp;
    for (int i = 3;;++i)
    {
        temp = i * i * 114 - 514;
        a[++n] = temp;
        if(temp > 1e9) break;
    }
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    cin >> t;
    while (t--)
    {
        cin >> k;
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if(a[i] < k)
            {
                ans += (i + 1) * (a[i] - a[i - 1]);
            }
            else{
                ans += (i + 1) * (k - a[i - 1] + 1);
                break;
            }
        }
        cout << ans << endl;
    }
	return 0;
}