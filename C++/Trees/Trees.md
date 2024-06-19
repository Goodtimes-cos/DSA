# Trees
### Characteristics of trees
A tree data structure is comprised of:
    - Roots
    - Children
    - Leaves

The properties of a tree are:
- Every tree has a special node called the root node. The root node can be used to traverse
every node of the tree. It's called the root because the tree originated from the root only.
- If a tree has N vertices(nodes) than the number of edges is always one less than the number
of nodes(vertices)
- Every child has a single parent, but a parent can have multiple children

### Types of tree
#### General tree
A tree is called a general tree when there is no constraint imposed on the hierarchy of the
tree. In a general tree, each node can have infinite children.

#### Binary tree
Binary tree is type of tree where each parent can have at most two children. The children are
referred to as left child or right child. This is one of the most commonly used trees.

#### Binary search tree
BST is an extension of Binary tree with some added constraints. In BST, the value of the left child
of a node must be smaller than or equal to the value of its parent and the value of the right child
is always larger than or equal to the value of its parent.

#### AVL tree
AVL tree is self-balancing binary search tree. In AVL tree, each node is assigned a balancing factor
based on which it is calculated whether the three is balanced or not. In AVL tree, the heights of children
differ by at most 1. The valid balancing factors are 1, 0, and -1. When a new node is added to
the AVL tree and tree becomes unbalanced then rotation is done to make sure that the tree remains
balanced.

#### Red-Black tree
Red-Black is another type of self-balancing tree.
 
### Tree traversal techniques
A Tree data structure can be traversed in the following ways:
- Depth First Search or DFS
    - Inorder traversal
    - Preorder traversal
    - Postorder traversal
- Level order traversal or BFS

#### Inorder traversal
The algorithm is as follows:
    - Traverse the left subtree,
    - Visit the root,
    - Traverse the right subtree.

#### Preorder traversal
The algorithm is as follows:
    - Visit the root
    - Traverse the left subtree
    - Traverse the right subtree

#### Postorder traversal
The algorithm is as follows:
    - Traverse the left subtree,
    - Traverse the right subtree,
    - Visit the root

#### Level Order traversal (Otherwise known as BFS)
Level Order Traversal visits all nodes present in the same level completely before visiting the next

The algorithm is as follows:
- Create an empty queue Q,
- Enqueue the root node of the tree to Q,
- Loop while Q is not empty
    - Dequeue a node from Q and visit it,
    - Enqueue the left child of the dequeued node if it exists,
    - Enqueue the right child of the dequeued node if it exists
