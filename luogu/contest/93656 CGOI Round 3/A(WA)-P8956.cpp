#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MOD = 998244353ll;
ll t,n,a,b,x,y;
vector<ll> f1(1000),f2(1000);
inline ll mod(ll temp){temp %= MOD;if (temp < 0) temp += MOD;return temp;}
ll qpow(ll t1,ll t2)
{
    if (t2 == 0) return 1;
    if (t2 == 1) return t1;
    if (t2 & 1) return mod(qpow(t1,t2 >> 1) * qpow(t1,t2 >> 1) * t1);
    else return mod(qpow(t1,t2 >> 1) * qpow(t1,t2 >> 1));
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        ll ans = 1;
        cin >> n >> a >> b >> x >> y;
        // f1.clear(),f2.clear();
        f1[0] = a,f1[1] = b,f2[0] = x,f2[1] = y;
        ll i = 0;
        for (; i < min(n,2ll);++i)
        {
            ans *= f2[i] - f1[i];
            // cerr << '@' << f1[i] << " " << f2[i] << endl;
        }
        ans = mod(ans);
        i = 2;
        for (;i < n;++i)
        {
            f1[i] = mod((ll) (sqrtl(f1[i-1] * f1[i-2])) + 1ll);
            f2[i] = mod((ll) (sqrtl(f2[i-1] * f2[i-2])) + 1ll);
            // cerr << '@' << f1[i] << " " << f2[i] << endl;
            // cerr << "ans: " << ans << '*' << (f2[i] - f1[i]) << " = ";
            ans = mod(ans * (f2[i] - f1[i]));
            // cerr << ans << endl;
            if((f1[i] == f1[i - 1] || f1[i] == f1[i - 1] + 1) && (f2[i] == f2[i - 1] || f2[i] == f2[i - 1] + 1)
             && (n - i - 1) % 2 == 0) break;
        }
        if (i >= n){ cout << ans << endl; continue;}
        if ((f1[i - 1] == f1[i - 2] && f2[i - 1] == f2[i - 2]) || (f1[i - 1] == f1[i - 2] + 1 && f2[i - 1] == f2[i - 2] + 1))
        // 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9,
        // 1, 4, 3, 4, 4, 5, 5, 6, 6, 7, 7,
        {
            ans = mod(ans * qpow(f2[i - 1] - f1[i - 1],n - i - 1));
            // cerr << "qpow(" << f2[i - 1] - f1[i - 1] << " " << n - i - 1 << endl;
        }
        else 
        // 1 1 2 2 3 3 4 4
        // 2 3 3 4 4 5 5 6
        {
            ans = mod(ans * qpow((f2[i - 1] - f1[i - 1]) * (f2[i - 2] - f1[i - 2]),(n - i - 1) / 2));
            // cerr << "qpow(" << (f2[i - 1] - f1[i - 1]) * (f2[i - 2] - f1[i - 2]) << " " << (n - i - 1) / 2 << endl;
        }
        cout << ans << endl;
    }
    return 0;
}