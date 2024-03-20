from pprint import pprint


class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        ans = 0
        minn = 10**4
        for price in prices:
            if price < minn:
                minn = price
            ans = max(ans, price - minn)
        return ans


pprint(Solution().maxProfit([1, 2, 3, 3, 3, 3, 4, 5, 9]))
