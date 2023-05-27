#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin >> n;
	char temp = 'a';
    for(;n > 0;--n)
	{
		cout << temp++;
		if(temp > 'z')
		{
			break;
		}
	}
	temp = 'z';
	while(--n > 0)
	{
		cout << temp--;
        if(temp <= 'a')
			temp = 'z';
	}
	return 0;
}