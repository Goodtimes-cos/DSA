# Implementation of a Binary Search Tree using Python3!

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def searchTree(value, root):
    if root == None:
        return False
    else:
        if value == root.value:
            return True
        elif value < root.value:
            return searchTree(value, root.left)
        else:
            return searchTree(value, root.right)

# Method we use to insert nodes into our binary tree
def insertNode(value, root):
    if root == None:
        return Node(value)
        
    if (value < root.value):
        root.left = insertNode(value, root.left)
    elif (value > root.value):
        root.right = insertNode(value, root.right)
        
    return root

# Find the inorder successor
def minValueNode(node):
    current = node

    # Find the leftmost leaf
    while(current.left is not None):
        current = current.left

    return current

def removeNode(value, root):
    if value < root.value:
        root.left = removeNode(value, root.left)
    elif value > root.value:
        root.right = removeNode(value, root.right)
    else:
        # If the node is with one child, or no children...
        if root.left == None:
            temp = root.right
            root = None
            return temp
        elif root.right == None:
            temp = root.left
            root = None
            return temp
        else:
            temp = minValueNode(root.right)
            root.value = temp.value
            root.right = removeNode(temp.value, root.right)
        # If the node has two children, place the inorder sucessor
        # in place of position of the node to be deleted.

    return root

def printPreOrder(root):
    if root != None:
        print(root.value)
        printInOrder(root.left)
        printInOrder(root.right)


def printInOrder(root):
    if root != None:
        printInOrder(root.left)
        print(root.value)
        printInOrder(root.right)

def printPostOrder(root):
    if root != None:
        printInOrder(root.left)
        printInOrder(root.right)
        print(root.value)


rootTree = None
rootTree = insertNode(5, rootTree)
printInOrder(rootTree)
print("==============\n")
rootTree = insertNode(5, rootTree)
rootTree = insertNode(4, rootTree)
rootTree = insertNode(6, rootTree)
printInOrder(rootTree)
print("==============\n")
rootTree = removeNode(5, rootTree)
printInOrder(rootTree)