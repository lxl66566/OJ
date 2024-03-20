from pprint import pprint


# 看了题解
class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        f = []
        for i in range(0, len(s)):
            flag = False
            for word in wordDict:
                if i + 1 < len(word):
                    continue
                if s[i - len(word) + 1 : i + 1] == word:
                    flag = f[i - len(word)] if i >= len(word) else True
                    if flag:
                        break
            f.append(flag)
        return f[-1]


pprint(Solution().wordBreak(s="leetcode", wordDict=["leet", "code"]))
