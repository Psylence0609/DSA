def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            if root.left is None and root.right is None: return None
            if root.left is None or root.right is None:
                return root.left if root.left else root.right
            temp = root.left
            while temp.right is not None:
                temp = temp.right
            root.val = temp.val
            root.left = self.deleteNode(root.left, temp.val)
        return root