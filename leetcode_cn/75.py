from pprint import pprint


# 写到后面我也不懂我在写什么玩意了。
# 主要是想尝试一下，除了循环变量，不使用其他空间
class JUST_A_PLAY:
    def sortColors(self, nums: list[int]) -> None:
        def simplecheck():
            if len(nums) == 1:
                return True
            if len(nums) == 2:
                if nums[0] > nums[1]:
                    [nums[0], nums[1]] = [nums[1], nums[0]]
                return True
            assert len(nums) >= 3
            for i in range(len(nums) - 1):
                if nums[i] > nums[i + 1]:
                    return False
            return True

        if simplecheck():
            return

        def find_and_replace(index: int):
            """
            如果 0 1 2 位置上的数不是索引自身，则从后面找数交换。找不到则在外部额外处理
            """
            if nums[index] != index:
                for i in range(index + 1, len(nums)):
                    if nums[i] == index:
                        [nums[index], nums[i]] = [nums[i], nums[index]]
                        return True
            else:
                return True
            return False

        # 聚集 0 1 2 的个数到 nums[0] [1] [2] 的位置
        for i in range(3):
            if not find_and_replace(i):
                if i < nums[i]:
                    nums[i] *= -1  # 换不了，但是自身的值需要给后面的数用，用负数标记
                else:
                    nums[i] = 0
            else:
                nums[i] = 1
                for j in nums[i + 1 :]:
                    if j == i:
                        nums[i] += 1
        for i in range(2, -1, -1):
            for j in range(i):
                if nums[j] == -i:
                    nums[i] += 1
                    nums[j] = 0
        for i in range(3):
            if nums[i] < 0:
                nums[i] = 0

        pprint(nums)

        # 填充，从尾部填充到头部
        if nums[2] > 0:
            # 用尾部暂存，防止填充过程被覆盖
            # 只有三个数时尾部暂存也会被覆盖
            nums[-1], nums[1] = nums[1], nums[-1]
            for i in range(
                len(nums) - 2,
                len(nums) - 1 - (nums[2] if len(nums) > 3 else nums[1]),
                -1,
            ):
                nums[i] = 2
            for i in range(nums[0], nums[0] + nums[-1]):
                if i == 0:
                    nums[-1] = -99
                nums[i] = 1
            if nums[-1] >= 0:
                for i in range(nums[0]):
                    nums[i] = 0
            nums[-1] = 2

        else:
            # 没有 2
            for i in range(nums[0], len(nums)):
                nums[i] = 1
            for i in range(nums[0]):
                nums[i] = 0


class Solution:
    def sortColors(self, nums: list[int]) -> None:
        a = [0, 0, 0]
        for i in nums:
            a[i] += 1
        for i in range(len(nums)):
            if i >= a[0] + a[1]:
                nums[i] = 2
            elif i >= a[0]:
                nums[i] = 1
            else:
                nums[i] = 0


a = [1, 2, 2]
Solution().sortColors(a)
print(a)
