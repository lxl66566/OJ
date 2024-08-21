from pprint import pprint


class Solution:
    def isArraySpecial(self, nums: list[int], queries: list[list[int]]) -> list[bool]:
        pre = preprocess(nums)
        ans = []
        for req in queries:
            ans.append(req[1] <= pre[req[0]])
        return ans


def preprocess(nums: list[int]) -> list[int]:
    pre = []
    last = 0
    for i in range(1, len(nums)):
        if not diff(nums[i - 1], nums[i]):
            for j in range(last, i):
                pre.append(i - 1)
            last = i
    for j in range(last, len(nums)):
        pre.append(len(nums) - 1)
    # print(pre)
    return pre


def diff(n1, n2):
    return (n1 & 1) ^ (n2 & 1)


ins = Solution()
pprint(ins.isArraySpecial([3, 4, 1, 2, 6], [[0, 4], [2, 3]]))
