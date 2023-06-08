#include <iostream>
#include <string>
#include <vector>

using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using u64 = uint64_t;

inline i32 map(const char &c) {
    if (c <= '9') return c - '0';
    return c - 'A' + 10;
}
string add(const string &a, i32 j) {
    string c;
    for (size_t i = 0; i < a.size(); ++i) {
        c.push_back(map(a[i]) + map(a[a.size() - i - 1]));
    }
    auto flag = false;
    for (auto i = c.rbegin(); i != c.rend(); ++i) {
        if (flag) {
            ++*i;
            flag = false;
        }
        if (*i >= j) {
            flag = true;
            *i -= j;
        }
        if (*i < 10)
            *i += '0';
        else
            *i += 'A' - 10;
    }
    if (flag) {
        c.insert(c.begin(), 1, '1');
    }
    cerr << '@' << c << endl;
    return c;
}
bool h(const string &a) {
    for (auto i = 0; i < a.size() / 2; ++i) {
        if (a[i] != a[a.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
i32 main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    i32 j;
    cin >> j >> s;
    for (auto i = 0; i < 30; ++i) {
        if (h(s)) {
            cout << "STEP=" << i << endl;
            return 0;
        }
        s = add(s, j);
    }
    cout << "Impossible!" << endl;
    return 0;
}