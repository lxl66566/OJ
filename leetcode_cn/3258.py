from typing import Callable


class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        zero, one = 0, 0
        i, j = 0, 0
        ans = 0
        f: Callable[[int], int] = lambda x: x * (x + 1) // 2

        def process(index, value=1):
            nonlocal zero, one
            if s[index] == "0":
                zero += value
            else:
                one += value

        while j < len(s):
            process(j)
            j += 1
            while i < j and min(zero, one) > k:
                # print(i, j, zero, one)
                ans += len(s) - j + 1
                process(i, -1)
                i += 1

        while i < len(s) and min(zero, one) > k:
            # print(i, j)
            ans += 1
            process(i)
            i += 1

        ans = f(len(s)) - ans
        return ans


if __name__ == "__main__":
    s = Solution()
    print(s.countKConstraintSubstrings("10101", 1))  # 12
    print(s.countKConstraintSubstrings("1010101", 2))  # 25
    print(s.countKConstraintSubstrings("11111", 1))  # 15
    print(s.countKConstraintSubstrings("0011", 1))  # 9
    print(s.countKConstraintSubstrings("000011", 1))  # 18
    print(s.countKConstraintSubstrings("0001", 1))  # 10
    print(s.countKConstraintSubstrings("001010", 1))  # 16
