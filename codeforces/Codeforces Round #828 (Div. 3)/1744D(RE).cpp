#include <iostream>
using namespace std;
#define ll long long
int t,n,num2,temp,ans,tominus;
int h[200005];
void pd()
{
    int temp2;
    for(int i=1;i<200001;i++)
    {
        temp2 = i;
        while (!(temp2 & 1))
            ++h[i],temp2 >>= 1;
    }
}
int main()
{
    pd();
    cin >> t;
    while (t--)
    {
        cin >> n;
        num2 = 0;
        for(int i=0; i<n; i++)
        {
            cin >> temp;
            num2 += h[temp];
        }
        if(n == 1){cout << (temp % 2 == 0 ? 0 : -1) << endl;continue;}
        // need n 2 but has num2 2
        if(num2 >= n)
        {
            cout << 0 << endl;
            continue;
        }

        tominus = n - num2,ans = 0,temp = n;
        int nearest2n = 1,now = 0,has;

        while(temp > 1) nearest2n *= 2,temp >>= 1;
        // cout << nearest2n << "@\n";

        for(;nearest2n >= 2;nearest2n /= 2)
        {
            has = n / nearest2n - now;
            now += has;
            if(tominus > has * h[nearest2n])
            {
                ans += has;
                tominus -= has * h[nearest2n];
                continue;
            }
            ans += tominus / h[nearest2n] + (tominus % h[nearest2n] ? 1 : 0);
            tominus = -1;
            break;
        }
        if(tominus <= 0)
            cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}