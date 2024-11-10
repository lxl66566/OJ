# 去除字符串中的所有 "pdd"

import re


def solve(s: str):
    ans = 0
    while True:
        s, n = solve_once(s)
        ans += n
        if n == 0:
            return s, ans


def solve_once(s: str):
    res = re.sub(r"pdd", "", s, flags=re.IGNORECASE)
    return res, (len(s) - len(res)) // 3


if __name__ == "__main__":
    print(solve("asfuhalflppddddadlhjafpdaslfjldpddkajshflsd0"))
