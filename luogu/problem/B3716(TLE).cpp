#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
namespace IO{//by cyffff
	char ibuf[(1<<20)+1],*iS,*iT;
	#if ONLINE_JUDGE
	#define gh() (iS==iT?iT=(iS=ibuf)+fread(ibuf,1,(1<<20)+1,stdin),(iS==iT?EOF:*iS++):*iS++)
 	#else
	#define gh() getchar()
	#endif
	inline i32 read(){
		char ch=gh();
		i32 x=0;
		bool t=0;
		while(ch<'0'||ch>'9')   t|=ch=='-',ch=gh();
		while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=gh();
		return t?-x:x;
	}
}
static array<i32,static_cast<i32>(1e4 + 12)> init() {
    static array<i32,static_cast<i32>(1e4 + 12)> notprime{};
    notprime[0] = notprime[1] = 1;
    for (i32 i = 2; i * i <= 1e4 + 12; ++i) {
        if (!notprime[i]) {
            for (i32 j = i * i; j <= 1e4 + 12; j += i) {
                notprime[j] = 1;
            }
        }
    }
    return notprime;
}
i32 main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    static auto notprime = init();
    vector<i32> primes;
    for (i32 i = 2;i < notprime.size();++i) {
        if (!notprime[i]) {
            primes.push_back(i);
        }
    }
    i32 t,n;
    t = IO::read();
    while (t--) {
        n = IO::read();
        i32 ans = 0;
        for (i32 i = 0; primes[i]*primes[i] <= n; ++i) {
            i32 temp2 = 0;
            while (n % primes[i] == 0) {
                ++temp2;
                n /= primes[i];
            }
            if (temp2 & 1) ans ^= primes[i];
        }
        if (n > 1) {
            ans ^= n;
        }
        cout << ans << endl;
    }
    return 0;
}
