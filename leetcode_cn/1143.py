# 668 ms
# class Solution:
#     def longestCommonSubsequence(self, text1: str, text2: str) -> int:
#         dp: list[list[int]] = []

#         def idx(i: int, j: int):
#             if i < 0 or j < 0:
#                 return 0
#             else:
#                 return dp[i][j]

#         for i in range(len(text1)):
#             dp.append([])
#             for j in range(len(text2)):
#                 if text1[i] == text2[j]:
#                     dp[i].append(idx(i - 1, j - 1) + 1)
#                 else:
#                     dp[i].append(max(idx(i - 1, j), idx(i, j - 1)))

#         return idx(len(text1) - 1, len(text2) - 1)


# 450 ms，不需要通过 if 判断路径，更快了。
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp: list[list[int]] = []

        for i in range(len(text1) + 1):
            dp.append([0] * (len(text2) + 1))

        for i in range(0, len(text1)):
            for j in range(0, len(text2)):
                if text1[i] == text2[j]:
                    dp[i + 1][j + 1] = dp[i][j] + 1
                else:
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j])

        return dp[-1][-1]


if __name__ == "__main__":
    s = Solution()
    print(s.longestCommonSubsequence("abcde", "ace"))
    print(s.longestCommonSubsequence("abc", "abc"))
    print(s.longestCommonSubsequence("abc", "def"))
