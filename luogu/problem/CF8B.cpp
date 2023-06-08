#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using u64 = uint64_t;

struct SimpleHash {
    size_t operator()(const std::pair<int, int> &p) const {
        return (p.first * 10000) + p.second;
    }
};
unordered_set<pair<i32, i32>, SimpleHash> a;

i32 main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    cin >> s;
    pair<i32, i32> now, last;
    for (auto const &c : s) {
        last = now;
        switch (c) {
        case 'U': now.first++; break;
        case 'D': now.first--; break;
        case 'L': now.second--; break;
        case 'R': now.second++; break;
        default: break;
        }
        if (a.count(now)) {
            cout << "BUG" << endl;
            return 0;
        }
        a.insert(std::make_pair(last.first + 1, last.second));
        a.insert(std::make_pair(last.first - 1, last.second));
        a.insert(std::make_pair(last.first, last.second + 1));
        a.insert(std::make_pair(last.first, last.second - 1));
        // for (auto const &i : a) {
        //     cerr << '@' << i.first << " " << i.second << endl;
        // }
    }
    cout << "OK" << endl;
    return 0;
}