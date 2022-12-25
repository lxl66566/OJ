#include <iostream>
#include <deque>
#define ll long long
using namespace std;
class state
{
public:
    char c;
    char s; // l,r,m
    int times;
    state(char c,char s,int times);
};
state::state(char temp,char s = 'm',int times = 0) : c(temp) ,s(s), times(times) {};
string input;
deque<state> q;
ll ans;
state last_pushback;
inline int absc(char a,char b)  // b to a
{
    return a - b < 0 ? a - b + 26 : a - b;
}
void push_check(state temp)
{
    if (temp.s == 'l' && last_pushback.s == 'r')
    {
        ans -= min(temp.times,last_pushback.times);
    }
    if(temp.c == last_pushback.c)
    {
        q.pop_back();
    }
    q.push_back(temp);
    last_pushback = temp;
}
char deal(char a,char b,char c)
{
    if(a == c)
    {
        int temp = b < a ? a - b : a - b + 26;
        ans += temp;
        push_check (state(a,'m',temp));
        return a;
    }
    auto tempfunc = [](int temp1,int temp2){return temp1 + temp2 - min(temp1,temp2);};
    int aa = tempfunc(absc(a,b),absc(a,c)), bb = tempfunc(absc(b,a),absc(b,c)), cc = tempfunc(absc(c,a),absc(c,b));
    switch(min(aa,bb,cc)){
        
    }
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> input;
    char temp = '0';
    for(auto i : input)
    {
        if(i != temp)
        {
            q.push_back(state(i));
            temp = i;
        }
    }
    char last = 'm';

	return 0;
}