from pprint import pprint


class Solution:
    def countPairs(self, nums: list[int], target: int) -> int:
        nums.sort()
        ans = 0
        i = 0
        j = len(nums) - 1
        while i < j:
            while nums[i] + nums[j] >= target and j >= i:
                j -= 1
            if j >= i:
                ans += j - i
            i += 1
        return ans


pprint(Solution().countPairs(nums=[-1, 1, 2, 3, 1], target=2))
pprint(Solution().countPairs([-6, 2, 5, -2, -7, -1, 3], target=-2))
