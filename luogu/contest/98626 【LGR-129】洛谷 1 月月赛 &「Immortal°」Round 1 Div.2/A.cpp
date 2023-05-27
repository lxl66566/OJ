#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;
typedef long long ll;
int t,n,m;
string s;
vector<string> problem;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t >> n >> m;
    for (int i=0;i<m;i++)
    {
        cin >> s;
        problem.push_back(s);
    }
    bool flag = true;
    bool zuzong = false;
    for (int i=0;i<n;i++)
    {
        flag = true;
        zuzong = false;
        for (int j=0;j<m;j++)
        {
            cin >> s;
            if(zuzong)
            {
                cin >> s;
                continue;
            }
            if (!regex_match(s,regex("^(freopen\\(\\\"" + problem[j] + "\\.in\\\",\\\"r\\\",stdin\\);)$")))
            {
                if (regex_match(s,regex("^(//freopen\\()(.*)(\\);)$")))
                {
                    zuzong = true;
                }
                else flag = false;
            }
            cin >> s;
            if (!regex_match(s,regex("^(freopen\\(\\\"" + problem[j] + "\\.out\\\",\\\"w\\\",stdout\\);)$")))
            {
                if (regex_match(s,regex("^(//freopen\\()(.*)(\\);)$")))
                {
                    zuzong = true;
                }
                else flag = false;
            }
        }
        if (zuzong) 
        {
            cout << "Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI." << endl;
        }
        else if (!flag)
            cout << "Good luck and have fun." << endl;
        else cout << "PION2202 RP++." << endl;
    }
    return 0;
}