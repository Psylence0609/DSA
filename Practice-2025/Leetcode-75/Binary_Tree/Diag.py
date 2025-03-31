import queue

class Node:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None


def diagonal(root):
    depth = {}
    q = queue.Queue()
    # if root is None:
    #     depth[0] = root
    #     return depth
    q.put((root, 0))
    while not q.empty():
        node, d = q.get()
        if node is None:
            continue
        if d in depth:
            depth[d].append(node.data)
        else:
            depth[d] = [node.data]
        if node.right:
            q.put((node.right, d))
        if node.left: q.put((node.left, d + 1))
    return depth


def printList(v):
    print(" ".join(map(str, v)))


if __name__ == "__main__":

    # Create a hard coded tree
    #         8
    #       /   \
    #     3      10
    #    /      /  \
    #   1      6    14
    #         / \   /
    #        4   7 13
    root = Node(8)
    root.left = Node(3)
    root.right = Node(10)
    root.left.left = Node(1)
    root.right.left = Node(6)
    root.right.right = Node(14)
    root.right.right.left = Node(13)
    root.right.left.left = Node(4)
    root.right.left.right = Node(7)

    ans = diagonal(root)
    print(ans)