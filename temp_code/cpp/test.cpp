#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, d;
    // cin >> n >> k >> d;
    for (int i = -1000; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
        }
    }
    ++n;
    if (n % k == d)
    {
        cout << n << endl;
        return 0;
    }
    if (n % k < d)
    {
        n += (d - n % k);
    }
    else
    {
        n += (k + d - n % k);
    }
    cout << n << endl;
    return 0;
}
// #include <iostream>
// int main()
// {
//     std::cout << -1000 << " " << 8 << " " << 999 << std::endl;
// }