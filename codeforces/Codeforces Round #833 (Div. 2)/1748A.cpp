#include<iostream>
using namespace std;
int temp;
int t,n;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << n / 2 + n % 2 << endl;
	}
    return 0;
}