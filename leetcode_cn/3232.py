class Solution:
    def canAliceWin(self, nums: list[int]) -> bool:
        a, b = 0, 0
        for i in nums:
            if i >= 10:
                a += i
            else:
                b += i
        return not a == b


if __name__ == "__main__":
    sol = Solution()
    print(sol.canAliceWin([1, 2, 3, 4, 10]))
