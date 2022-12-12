#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
int t,n,num[51],flag;
char a[51];
string s;
int main()
{
    cin >> t;
    while (t--) 
    {
        cin >> n;
        flag = 0;
        for(int i = 1;i <= n;i++)
        {
            cin >> num[i];
        }
        memset(a,0,sizeof(a));
        cin >> s;
        for(int i = 1;i <= n;i++)
        {
            if(a[num[i]] == 0)
            {
                a[num[i]] = s[i - 1];
                continue;
            }
            if(s[i - 1] != a[num[i]])
            {
                flag = 1;
                break;
            }
        }
        if(!flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}