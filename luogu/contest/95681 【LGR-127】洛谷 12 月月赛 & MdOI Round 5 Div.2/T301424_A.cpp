#include <iostream>
#define ll long long
using namespace std;
int t,n;
int f(int x,int y)
{
    if(y - x <= 1) return y;
    int mid = (x+y)/2;
    if((1 << x) - 1 < n && n <= (1 << mid) - 1) return f(x,mid);
    else return f(mid,y);
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1) {cout << 1 << endl;continue;}
        if(n % 2 == 0) cout << -1 << endl;
        else cout << f(1,30) << endl;
    }
	return 0;
}