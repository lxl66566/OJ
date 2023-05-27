#include<iostream>
using namespace std;
int temp;
int t,n,a[100005],f[10],rec[10],ans;
char tempc;
inline int pd()
{
	int maxn = 0,typ = 0;
	for(int i = 0; i < 10; i++)
	{
		if(f[i]) ++ typ;
		if(f[i] > maxn) maxn = f[i];
	}
	if(maxn <= typ) ++ ans;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> t;
	while (t--)
	{
		for(int i = 0; i < 10; i++) f[i] = rec[i] = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> tempc;
			a[i] = tempc - '0';
		}

		ans = n;
		++rec[a[1]];
		for(int i = 2; i <= n; i++)
        {
			rec[a[i]] ++;
			for(int k = 0;k < 10;++k) f[k] = rec[k];
			for(int j = 1; j + i - 1 <= n; j++)
			{
				if(j != 1) f[a[j - 1]] --,f[a[j + i - 1]] ++;
				pd();
			}
		}
		cout << ans << endl;
	}
    return 0;
}