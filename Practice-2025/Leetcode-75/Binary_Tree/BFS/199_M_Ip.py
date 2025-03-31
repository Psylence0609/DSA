def pre_order(self,root,d):
        if root:
            self.pre_order(root.left, d + 1)
            self.a[d] = root.val
            self.pre_order(root.right , d + 1)


def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
    self.a = {}
    self.pre_order(root, 0)
    return[self.a[i] for i in sorted(self.a)]

def isLeaf(node):
    return node.left is None and node.right is None

# Function to collect left boundary nodes
# (top-down order)
def collectBoundaryLeft(root, res):
    if root is None or isLeaf(root):
        return

    res.append(root.data)
    if root.left:
        collectBoundaryLeft(root.left, res)
    elif root.right:
        collectBoundaryLeft(root.right, res)

# Function to collect all leaf nodes
def collectLeaves(root, res):
    if root is None:
        return

    if isLeaf(root):
        res.append(root.data)
        return

    collectLeaves(root.left, res)
    collectLeaves(root.right, res)

# Function to collect right boundary nodes
# (bottom-up order)
def collectBoundaryRight(root, res):
    if root is None or isLeaf(root):
        return

    if root.right:
        collectBoundaryRight(root.right, res)
    elif root.left:
        collectBoundaryRight(root.left, res)

    res.append(root.data)

# Function to find Boundary Traversal of Binary Tree
def boundaryTraversal(root):
    res = []

    if not root:
        return res

    # Add root data if it's not a leaf
    if not isLeaf(root):
        res.append(root.data)

    # Collect left boundary
    collectBoundaryLeft(root.left, res)

    # Collect leaf nodes
    collectLeaves(root, res)

    # Collect right boundary
    collectBoundaryRight(root.right, res)

    return res