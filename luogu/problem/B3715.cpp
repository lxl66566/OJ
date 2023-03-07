#include <iostream>
#include <cassert>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
static array<i64,static_cast<i64>(1e6)> init() {
    static array<i64,static_cast<i64>(1e6)> notprime{};
    notprime[0] = notprime[1] = 1;
    for (i64 i = 2; i * i <= 1e6; ++i) {
        if (!notprime[i]) {
            for (i64 j = i * i; j <= 1e6; j += i) {
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
    i64 t,n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (i64 i = 2; i < notprime.size(); ++i) {
            while (!notprime[i] && n % i == 0) {
                cout << i << ' ';
                n /= i;
            }
            if (n <= 1) break;
        }
        if (n > 1) {
            cout << n;
        }
        cout << endl;
    }
    return 0;
}
