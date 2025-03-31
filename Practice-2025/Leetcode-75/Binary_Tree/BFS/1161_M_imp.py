def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        q = queue.Queue()
        res = {}
        if root:
            q.put((root, 1))
        while not q.empty():
            node, level = q.get()
            res[level] = res.get(level, 0) + node.val
            if node.left: q.put((node.left, level + 1))
            if node.right: q.put((node.right, level + 1))
        res = sorted(res.items(), key = lambda item: (-item[1], item[0]))
        return res[0][0]