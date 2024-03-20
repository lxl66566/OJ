from pprint import pprint


class Solution:
    def rob(self, nums: list[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])
        f = [[0, 0], [nums[0], nums[1]]]
        for i in range(1, len(nums) - 1):
            f.append([max(f[i][0], f[i][1]), f[i][0] + nums[i + 1]])
        return max(*f[-1])


pprint(Solution().rob([1, 2, 3, 1]))
