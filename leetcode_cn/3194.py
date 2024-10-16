class Solution:
    def minimumAverage(self, nums: list[int]) -> float:
        minn = 10**9
        nums.sort()
        for i in range(len(nums) - 1):
            minn = min(minn, (nums[i] + nums[len(nums) - i - 1]) / 2)
        return minn


print(Solution().minimumAverage([7, 8, 3, 4, 15, 13, 4, 1]))
