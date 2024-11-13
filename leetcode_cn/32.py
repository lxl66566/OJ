# 尝试使用栈模拟，结果发现有 case `(()` 无法处理。然后用 last_0 修补，更烂了。
# class Solution:
#     def longestValidParentheses(self, s: str) -> int:
#         stack = 0
#         ans = 0
#         last = -1
#         last_0 = -1
#         for i in range(len(s)):
#             if s[i] == "(":
#                 stack += 1
#             else:
#                 stack -= 1
#                 if stack < 0:
#                     stack = 0
#                     ans = max(ans, i - last - 1)
#                     last = i
#                     last_0 = i
#                 elif stack == 0:
#                     ans = max(ans, i - last_0)
#                     last_0 = i
#         if stack != 0:
#             ans = max(ans, len(s) - last_0 - 1 - stack)
#         return ans

# 看了题解
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        return max(self.sub(s), self.sub(s[::-1], ")"))

    def sub(self, s: str, re: str = "(") -> int:
        l, r = 0, 0
        ans = 0
        for i in range(len(s)):
            if s[i] == re:
                l += 1
            else:
                r += 1
                if r > l:
                    l, r = 0, 0
            if l == r:
                ans = max(ans, l + r)
        return ans


if __name__ == "__main__":
    s = Solution()
    print(s.longestValidParentheses("()())()"))  # 4
    print(s.longestValidParentheses("()(()"))  # 2
    print(s.longestValidParentheses(")("))  # 0
    print(s.longestValidParentheses("()"))  # 2
    print(s.longestValidParentheses("()()"))  # 4
    print(s.longestValidParentheses("(()"))  # 2
