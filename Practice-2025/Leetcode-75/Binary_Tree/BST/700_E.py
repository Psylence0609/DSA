def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if root.val == val:
            return root
        elif root.val < val :
            node = self.searchBST(root.right, val)
        else:
            node = self.searchBST(root.left, val)
        return node