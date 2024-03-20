from pprint import pprint


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        window = set()
        window.add(s[0])
        l = 0
        r = 0
        ans = 0
        while r < len(s) - 1:
            r += 1
            while s[r] in window:
                window.remove(s[l])
                l += 1
            window.add(s[r])
            ans = max(ans, r - l + 1)
        return ans


pprint(Solution().lengthOfLongestSubstring("abcabcbb"))
