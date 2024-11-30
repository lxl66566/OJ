class Solution:
    def reverse(self, x: int) -> int:
        y = 0
        m = False
        if x < 0:
            m = True
            x = -x
        while x:
            y = y * 10 + x % 10
            x //= 10
        ans = y if not m else -y
        if ans > 2**31 - 1 or ans < -(2**31):
            return 0
        return ans
