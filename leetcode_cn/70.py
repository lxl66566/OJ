from pprint import pprint


class Solution:
    def climbStairs(self, n: int) -> int:
        ans = [1, 1, 2]
        for i in range(2, n):
            ans.append(ans[-1] + ans[-2])
        return ans[n]


pprint(Solution().climbStairs(45))
