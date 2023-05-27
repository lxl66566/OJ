#include <iostream>
#define ll long long
using namespace std;
int n,m,a[100005];//,lastzero[100005];
string f;
// count how many zeros in front of string f
int countzero(){
    int cnt=0;
    for (auto c:f)
    {
        if(c == '0') ++ cnt;
        else break;
    }
    return cnt;
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> f;
    for(int i = 1; i <= n;++i)
    {
        cin >> a[i];
    }
    // int x = 0;
    // for(int i = 0; i <= f.size();++i)
    // {
    //     if(f[i] == '0')
    //     {
    //         x = i;
    //         lastzero[i] = i;
    //     }
    //     else{
    //         lastzero[i] = x;
    //     }
    // }
    if(n == m) {cout << n - countzero();return 0;}
    int ans = 0;
    for(int i = 1; i <= n;++i)
    {
        if(f[a[i] - ans] == '1') ans += 1;//lastzero[a[i] - ans];
    }
    cout << ans;
	return 0;
}