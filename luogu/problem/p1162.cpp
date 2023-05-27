#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
char a[32][32];
int n;
int dirx[] = {0,1,0,-1};
int diry[] = {1,0,-1,0};
int dfs(int i,int j)
{
    if(i<=0||j<=0||i>n||j>n|| a[i][j] != '0') return 0;
    a[i][j] = '2';
    for (int k = 0; k < 4; ++k)
    {
        dfs(i+dirx[k],j+diry[k]);
    }
    return 0;
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    pair<int,int> first1{0,0},last1{0,0};
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '1')
            {
                if (!first1.first) first1 = pair<int,int>{i,j};
                last1 = pair<int,int>{i,j};
            }
        }
    }
    dfs(first1.first + 1,first1.second + 1);
    dfs(last1.first - 1,last1.second - 1);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}