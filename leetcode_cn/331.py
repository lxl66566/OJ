from pprint import pprint


class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        p = preorder.split(",")
        stack = []
        for index, c in enumerate(p):
            if c == "#":
                if stack:
                    stack.pop()
                else:
                    return index == len(p) - 1
            else:
                stack.append(c)
        return False


pprint(Solution().isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"))
pprint(Solution().isValidSerialization("1,#"))
