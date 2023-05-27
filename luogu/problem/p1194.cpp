#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
struct node
{
    int l,r,w;
    bool operator< (const node &a)const{
        return w > a.w;
    }
};
priority_queue<node> m;
int a,b,w[501][501],f[501],ans,rec=1;
int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        f[i] = i;
    }
    for (int i = 1;i <= b;++i)
    {
        for (int j = 1;j <= b;++j)
        {
            cin >> w[i][j];
            if (i < j && w[i][j] != 0) m.push(node{i,j,w[i][j]});
        }
    }
    int k;
    for (k = 1;k < b && !m.empty();++k)
    {
        auto temp = m.top();m.pop();
        // cerr << '@' << temp.l << ' ' << temp.r << endl;
        if (temp.w > a) break;
        if (find(temp.l) == find(temp.r)) {--k;continue;}
        ans += temp.w;
        f[find(temp.r)] = find(temp.l);
    }
    // cerr << "k= " << k << endl;

    cout << ans + (b - k) * a + a;
    return 0;
}