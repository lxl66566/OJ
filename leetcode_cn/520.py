# https://leetcode.cn/problems/detect-capital/description/


class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if len(word) <= 1:
            return True
        if word[0].islower():
            return all(c.islower() for c in word)
        return all(c.islower() == word[1].islower() for c in word[2:])


s = Solution()
print(s.detectCapitalUse("USA"))
print(s.detectCapitalUse("FlaG"))
print(s.detectCapitalUse("leetcode"))
