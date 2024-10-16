# 子序列 是可以通过从另一个数组删除或不删除某些元素，但不更改其余元素的顺序得到的数组。
# 看错了，看成子数组了，用了双指针（滑动窗口），结果是动归。


class Solution:
    def find(self, expected: int, seq: list[int], begin: int = 0) -> int:
        return begin + seq[begin:].index(expected)

    def maximumLength(self, nums: list[int], k: int) -> int:
        # 差分 + 求和
        for i in range(1, len(nums)):
            nums[i] = int(nums[i] != nums[i - 1])
            nums[0] = 0
            nums[i] += nums[i - 1]

        print(nums)

        maxlen = 0
        l, r = 0, k
        l_index, r_index = 0, 0
        try:
            l_index = self.find(l, nums, l_index)
            r_index = self.find(r, nums, r_index)
            maxlen = max(r_index - l_index, maxlen)

        except ValueError:
            maxlen = max(maxlen, len(nums) - l)
            pass

        return maxlen


print(Solution().maximumLength(nums=[1, 2, 1, 1, 3], k=2))
print(Solution().maximumLength(nums=[1, 2, 3, 4, 5, 1], k=0))
