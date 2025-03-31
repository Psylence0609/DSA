def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.maxLength = 0
        self.dfs(root)
        return self.maxLength

def dfs(self, node: Optional[TreeNode]) -> tuple[int, int]:
    if not node:
        return (-1, -1)
    
    left = self.dfs(node.left)
    right = self.dfs(node.right)

    leftLen = left[1] + 1
    rightLen = right[0] + 1
    self.maxLength = max(self.maxLength, leftLen, rightLen)
    return (leftLen, rightLen)