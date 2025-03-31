def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.ans = 0
        cache = {0:1}

        self.dfs(root, targetSum, 0, cache)
        return self.ans
    
def dfs(self,root, target, currPathSum, cache):
    if root is None:
        return
    currPathSum += root.val
    oldPathSum = currPathSum-target
    self.ans += cache.get(oldPathSum, 0)
    cache[currPathSum] = cache.get(currPathSum, 0) + 1

    self.dfs(root.left, target, currPathSum, cache)
    self.dfs(root.right, target, currPathSum, cache)
    cache[currPathSum] -= 1 ## Important step: When you are shifting to a different branch the sum is not available anymore