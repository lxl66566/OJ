#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long ll;
int n;
unordered_set<string> mp;
unordered_set<string> names;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    names.reserve(n);
    for (int i = 1; i <= n; i++)
    {
        string name,temp;
        cin >> name >> temp;
        names.insert(name);
        if (temp != "No")
        {
            mp.insert(name);
            mp.insert(temp);
        }
    }
    int ans = 0;
    for(auto i : mp)
    {
        if (names.count(i)) ++ ans;
    }
    cout << n - ans;
    return 0;
}