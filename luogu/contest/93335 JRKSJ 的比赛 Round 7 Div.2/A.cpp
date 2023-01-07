#include <iostream>
#include <map>
#define ll long long
using namespace std;
string s;
ll q,p,ans;
char c;
inline auto fn2()
{
    return ans / 2 + ans % 2;
}
namespace IO{//by cyffff
	char ibuf[(1<<20)+1],*iS,*iT;
	#if ONLINE_JUDGE
	#define gh() (iS==iT?iT=(iS=ibuf)+fread(ibuf,1,(1<<20)+1,stdin),(iS==iT?EOF:*iS++):*iS++)
 	#else
	#define gh() getchar()
	#endif
	inline long long read(){
		char ch=gh();
		long long x=0;
		bool t=0;
		while(ch<'0'||ch>'9')   t|=ch=='-',ch=gh();
		while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=gh();
		return t?-x:x;
	}
	inline char getc(){
		char ch=gh();
		while(ch<'a'||ch>'z') ch=gh();
		return ch;
	}
    inline string getstring(){//manually add
    	string temp{};
		char ch=gh();
		while(ch<'a'||ch>'z') ch=gh();
		while(ch>='a'&&ch<='z') {temp.push_back(ch);ch=gh();}
        return temp;
    }
}
using IO::read;
using IO::getc;
using IO::getstring;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    q = read();
    s = getstring();
    ans = 1;
    for(int i=1;i < s.size();i++)
    {
        if(s[i] != s[i - 1]) ++ans;
    }
    cout << fn2() << endl;
    while(q--)
    {
        p = read(),c = getc();
        p --;
        // auto fn = [=]() -> int {
        //     int before = 0;
        //     if(p > 0 && s[p] != s[p - 1]) ++ before;
        //     if(p < s.size() - 1 && s[p] != s[p + 1]) ++ before;
        //     return before;
        // };
        if(p > 0 && s[p] != s[p - 1]) --ans;
        if(p < s.size() - 1 && s[p] != s[p + 1]) --ans;
        // ans -= fn();
        s[p] = c;
        if(p > 0 && s[p] != s[p - 1]) ++ans;
        if(p < s.size() - 1 && s[p] != s[p + 1]) ++ans;
        // ans += fn();
        cout << fn2() << endl;
    }
	return 0;
}