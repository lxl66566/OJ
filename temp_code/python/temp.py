class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        m = {}
        for i in nums:
            m[i] = m.get(i, 0) + 1
        for i in m:
            if m[i] == 1:
                return i


print(Solution().singleNumber([2, 2, 1, 2]))
