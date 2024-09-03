from functools import reduce
from pprint import pprint

pprint("")


class Solution:
    def maxStrength(self, nums: list[int]) -> int:
        pos = list(filter(lambda x: x >= 1, nums))
        ans = 0
        if pos:
            ans = reduce(lambda x, y: x * y, pos, 1)
        neg = iter(sorted(filter(lambda x: x <= -1, nums)))
        try:
            while i := next(neg):
                j = next(neg)
                if i * j < 1:
                    break
                if ans == 0:
                    ans = 1
                ans *= i * j
        except StopIteration:
            pass
        if ans == 0 and nums:
            ans = max(nums)
        return ans


pprint(Solution().maxStrength([3, -1, -5, 2, 5, -9]))
pprint(Solution().maxStrength([-4, -5, -4]))
pprint(Solution().maxStrength([-1, 0]))
pprint(Solution().maxStrength([-9]))
