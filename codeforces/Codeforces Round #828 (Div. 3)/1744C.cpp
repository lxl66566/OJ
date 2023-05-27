#include <iostream>
using namespace std;
#define ll long long
int t,n,flag,firstgreen,ans;
char now;
string s;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> now >> s;
        if(now == 'g')
        {
            cout << 0 << endl;
            continue;
        }
        ans = 0,flag = -1;
        firstgreen = -1;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'g')
            {
                if(firstgreen == -1) firstgreen = i;
                if(flag != -1)
                {
                    ans = max(ans,i - flag);
                    flag = -1;
                }
            }
            else if(s[i] == now)
            {
                if(flag == -1)
                {
                    flag = i;
                }
            }
        }
        if(flag != -1)
            ans = max(ans,n - flag + firstgreen);
        cout << ans << endl;
    }
    return 0;
}