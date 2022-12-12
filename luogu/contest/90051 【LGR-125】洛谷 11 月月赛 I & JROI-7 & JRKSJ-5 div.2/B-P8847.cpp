#include<iostream>
using namespace std;
int n,a[2],temp;
void cle()
{
	if(a[0] == 0) while(a[1]-- > 0) cout << 1 << ' ';
	else while(a[0]-- > 0) cout << -1 << ' ';
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		if(temp == 1) ++ a[1];
		else ++ a[0];
	}
	if(a[1] == 0 || a[0] == 0)
	{
		cle();
		return 0;
	}
	if(a[1] == a[0])
	{
		for(int i = 1;i < a[0]; i++)
		{
			cout << 1 << ' ' << -1 << ' ';
		}
		cout << -1 << ' ' << 1;
		return 0;
	}
	else if((a[1] - 1) * 2 <= a[0])
	{
		while(a[1])
		{
			cout << 1 << ' ';
			--a[1];
			for(int i = 1;i <= 2 && a[0] > 0;++i) {cout<< -1 << ' ';--a[0];}
		}
        cle();
		return 0;
	}
	else if(a[1] - 1 <= a[0])
	{
		while(a[1] - 1 > 0)
		{
			cout << 1 << ' ' << -1 << ' ';
            --a[1],--a[0];
		}
		while(a[0]-- > 0) cout << -1 << ' ';
		cout << 1;
		return 0;
	}
	else if(a[0] == 1)
	{
		int r = a[1] / 2;
		while(r-- > 0)
		{
			cout << 1 << ' ';
            --a[1];
		}
		cout << -1 << ' ';--a[0];
		cle();
        return 0;
	}
	else
	{
		int r = a[1] / a[0];
		temp = a[1] - r * a[0];if(temp) temp = 0;else temp = 1;
		while(a[0] > temp)
		{
			for(int i = 0; i < r;++i) cout << 1 << ' ';
			a[1] -= r;
			cout << -1 << ' ';
            --a[0];
		}
		if(a[0])
			{cout << -1 << ' ';--a[0];}
		cle();
        return 0;
	}
	return 0;
}