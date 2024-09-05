# https://leetcode.cn/problems/clear-digits/description/


class Solution:
    def clearDigits(self, s: str) -> str:
        ans = []
        for i in range(len(s)):
            if not s[i].isdigit():
                ans.append(s[i])
            else:
                if ans:
                    ans.pop()
                else:
                    return s[i + 1 :]
        return "".join(ans)


if __name__ == "__main__":
    s = "leet1234code234"
    print(Solution().clearDigits(s))
