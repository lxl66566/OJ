#include <iostream>
using namespace std;
#define ll long long
int t,n,q,odd,even,temp,ope;
ll total;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        odd = even = 0;
        total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            total += temp;
            if(temp & 1) ++odd;
            else ++ even;
        }
        while(q--)
        {
            cin >> ope >> temp;
            if(ope)
            {
                total += temp * odd;
                if(temp & 1) even += odd,odd = 0;
            }
            else{
                total += temp * even;
                if(temp & 1) odd += even,even = 0;
            }
            cout << total << endl;
        }
    }
    return 0;
}