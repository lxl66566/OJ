#include <iostream>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
class edge
{
	public:
		int from,to,w;
		edge(int from,int to,int w): from(from),to(to),w(w) {};
};
vector<edge> node[200005];
int t,n,a[200005],b[200005],x,y,temp1,temp2,temp3,flag;
void search(int id,int *s)
{
	if(flag || id == x) return;
	if(s[id] == 0) {flag = 1;return;}
	if(node[id].size() == 1) return;
	for(auto i : node[id])
	{
		if(s[i.to] != (s == a ? -1 : a[id] )) continue;
		s[i.to] = s[id] ^ i.w;
		search(i.to,s);
	}
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> t;
while (t--)
{
	cin >> n >> x >> y;
	for (int i = 1; i <= n;++i) {node[i].clear();a[i] = b[i] = -1;}
	flag = 0;a[x] = 0;
	for (int i = 1; i < n;++i)
	{
		cin >> temp1 >> temp2 >> temp3;
		node[temp1].push_back(edge(temp1,temp2,temp3));
		node[temp2].push_back(edge(temp2,temp1,temp3));
	}
	if(n == 2){cout << "NO" << endl;continue;}
	for(auto i : node[x])
	{
		a[i.to] = a[x] ^ i.w;
		search(i.to,a);
	}
	if(flag){cout << "YES" << endl;continue;}

	// cout << "@\n";
	// for (int i = 1; i <= n;++i)
	// {
	// 	cout << a[i] << ' ';
	// }
	// cout << endl;

	for(auto i : node[y])
	{
		b[i.to] = a[y] ^ i.w;
		search(i.to,b);
	}
	if(flag){cout << "YES" << endl;continue;}
	else cout << "NO" << endl;
}
	return 0;
}