#include <iostream>
#define ll long long
using namespace std;
string a,b;
char c[27];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
	cin >> a >> b;
	int i;
	for(i = 0; i < min(a.size(),b.size()); i++)
	{
		if(a[i] != b[i]) break;
	}
	if(i == min(a.size(),b.size()))
	{
		for (char d = 'a';d <= 'z';d++) cout << d;
		return 0;
	}
	cout << b[i] << a[i];
	c[b[i] - 'a'] = c[a[i] - 'a'] = 1;
	for(int i = 0;i < 26;++i)
	{
		if(c[i] == 0) cout << char('a' + i);
	}
	return 0;
}