# 3007 https://leetcode.cn/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k

from math import floor
from pprint import pprint


class Solution:
    def findMaximumNumber(self, k: int, x: int) -> int:
        a = []
        for i in range(1, 50):
            a.append(floor(i / x) * (1 << i) / 2)
            if a[-1] > 10**15:
                break
        i = len(a) - 1
        while i >= 0 and k > 0:
            if k >= a[i]:
                k -= a[i]
                a[i] = 1
            else:
                a[i] = 0
            i -= 1
        ans = array_to_int(a)
        while k > 0:
            print(k, ans)
            ans += 1
            k -= match_ones(ans, x)
        if k == 0:
            return ans
        else:
            return ans - 1


def match_ones(k, x):
    ans = 0
    for i in range(0, 50, x):
        if (1 << i) > k:
            break
        if (1 << i) & k != 0:
            ans += 1
    return ans


def array_to_int(arr):
    binary_string = "".join(str(bit) for bit in reversed(arr))
    return int(binary_string, 2)


print(Solution().findMaximumNumber(9, 1))  # 5 err!
print(Solution().findMaximumNumber(7, 2))  # 9
pprint("")
