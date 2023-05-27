#include<iostream>
#define ll long long
using namespace std;
int t,a[200005],ones,zeros,n,b[2],stop[2];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> t;
while (t--)
{
	cin >> n;
	ones = zeros = b[1] = b[0] = stop[1] = stop[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if(a[i]) ++ ones;
		else ++ zeros;
	}
	if(n == 1)
	{
		cout << 0 << endl;
		continue;
	}
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] == 0)
		{
			b[0] = zeros - 1 - (i - 1);
			stop[0] = i;
			break;
		}
	}
	for(int i = n; i >= 1; --i)
	{
		if(a[i] == 1)
		{
			b[1] = ones - 1 - (n - i);
			stop[1] = i;
			break;
		}
	}
	if(b[1] < 0 && b[0] < 0);
	else if(b[1] > b[0]) a[stop[1]] = 0,--ones,++zeros;
	else a[stop[0]] = 1,--zeros,++ones;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if(a[i] == 0) --zeros;
		else 
		{
			ans += zeros;
		}
	}
	cout << ans << endl;
}
	return 0;
}