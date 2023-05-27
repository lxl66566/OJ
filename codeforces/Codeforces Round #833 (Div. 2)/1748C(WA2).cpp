#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;
int t,n,temp;
ll b[200005];
unordered_map<int,int> m;
pair<int,int> get_max()
{
    pair<int,int> maxn = pair<int,int>(0,0);
    for(auto i = m.begin(); i != m.end();++i)
    {
        if((*i).second > maxn.second)
        {
            maxn = *i;
        }
    }
    return maxn;
}
inline void add_whether_exist(int a)
{
    if(m.count(a) != 0) ++m[a];
    else m.emplace(a,1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> b[i];
            b[i] += b[i - 1];
        }

        int p = 2,ans = 0;
        m.clear();
        if(b[1] == 0) ++ans;
        for(p = 2; p <= n; p++)
        {
            if(b[p] == b[p - 1]) break;    // find 0
        }
        for(;p <= n;)
        {
            if(p == n) {++ans;break;}
            add_whether_exist(b[p]);
            p++;
            for(;p <= n && b[p] - b[p - 1] != 0; p++)
            {
                add_whether_exist(b[p]);
            }
            auto temp = get_max();
            ans += temp.second;
            m.clear();
        }
        cout << ans << endl;
    }
    return 0;
}

// 1 0 0 1 -1 0 1 0 -1
// 1 1 1 2 1  1 2 2 1
//   1 2      1   1

// 2 2 3 2 2