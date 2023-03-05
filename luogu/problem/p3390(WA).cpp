#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
class matrix {
public:
    vector<vector<i64>> a;
    i64 n;
    matrix(i64 nn) :n(nn) {
        for (i64 i = 0; i < n; i++) {
            a.push_back(vector<i64>(n, 0));
        }
    }
    matrix operator*=(matrix b) {
        matrix c(n);
        for (i64 i = 0; i < n; i++) {
            for (i64 j = 0; j < b.n; j++) {
                i64 temp = 0;
                for (i64 k = 0; k < n; k++) {
                    temp = (a[i][k] * b.a[k][j]) % (static_cast<i64>(1e9) + 7LL);
                }
                c.a[i][j] = temp;
            }
        }
        return *this = c;
    }
    friend ostream& operator<<(ostream& os, const matrix& m) {
        for (i64 i = 0; i < m.n; i++) {
            for (i64 j = 0; j < m.n; j++) {
                os << m.a[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
    matrix power(i64 b) {
        auto res = I(n);
        matrix temp = *this;
        while (b) {
            if (b & 1) {
                res *= temp;
                // cerr << res << endl;
            }
            temp *= temp;
            b >>= 1;
        }
        return (*this = res);
    }
    matrix I(i64 n) {
        matrix temp(n);
        for (i64 i = 0; i < n; i++) {
            temp.a[i][i] = 1;
        }
        return temp;
    }
};
i32 main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
    i64 n,k;
    cin >> n >> k;
    matrix a(n);
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < n; j++) {
            cin >> a.a[i][j];
        }
    }
    cout << a.power(k) << endl;
    return 0;
}
