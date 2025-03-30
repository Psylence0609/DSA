def goodNodes(self, root: TreeNode) -> int:
        
        def dfs(node, max_local):
            if not node:
                return 0
            newMax = max(max_local, node.val)
            count_left = dfs(node.left,newMax)
            count_right = dfs(node.right, newMax)
            return int(node.val >= max_local) + count_left + count_right
        return dfs(root, -float('inf'))