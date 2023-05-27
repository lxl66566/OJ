#include<iostream>
#define ll long long
using namespace std;
ll k,t,a,b,p[1000006];
ll ans;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> k >> t >> a >> b;
	for(int i = 1;i <= t;i++)
	{
		cin >> p[i];
	}
	if(a == b)
	{
		for(int i = 1;i <= t;i++) ans += p[i];
		cout << ans * a;
		return 0;
	}
	if(a < b || k == 1)
	{
		ll ansa = 0;
		bool news = true;
		for(int i = 1;i <= t;i++)
		{
			if(p[i])
			{
				ans += p[i];
				if(news == true) {++ ansa;news = false;}
			}
			else{
				news = true;
			}
		}
		cout << (ans - ansa) * b + ansa * a;
		return 0;
	}
	int news[2]; news[1] = k; news[0] = 0;
	for(int i = 1;i <= t;i++)
	{
		if(p[i] == 0) {news[1] = k; news[0] = 0;continue;}
		if(news[1] == 0)
		{
			ans += p[i] * b;
			news[0] = 1;
			news[1] = k - 1;
			continue;
		}
		if(news[1] <= p[i])
		{
			ans += news[1] * a + (p[i] - news[1]) * b;
			news[0] = news[1];
			news[1] = k - news[0];
		}
		else{
			ans += p[i] * a;
			news[0] = p[i];
			news[1] = k - news[0];
		}
	}
	cout << ans;
	return 0;
}