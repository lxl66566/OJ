from pprint import pprint
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode], pa_val: int) -> int:
            thisval = pa_val * 10 + node.val
            if not node.left and not node.right:
                return thisval
            return (0 if not node.left else dfs(node.left, thisval)) + (
                0 if not node.right else dfs(node.right, thisval)
            )

        return dfs(root, 0)


pprint(Solution().sumNumbers(TreeNode(1, TreeNode(2), TreeNode(3))))
