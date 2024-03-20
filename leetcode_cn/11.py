from pprint import pprint


# 看了题解
class Solution:
    def maxArea(self, height: list[int]) -> int:
        l = 0
        r = len(height) - 1
        ans = 0
        while l < r:
            ans = max(ans, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans


pprint(Solution().maxArea([1, 2, 3, 3, 3, 3, 4, 5, 9]))
