#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int main()
{
    vector<int> a(15,2);
    cerr << a.capacity() << " " << a.size() << endl;
    a[5] = 9;
    cerr << a.capacity() << " " << a.size() << endl;
    return 0;
}