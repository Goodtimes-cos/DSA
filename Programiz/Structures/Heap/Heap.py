"""
Note: A complete binary tree is a special type of binary tree, where
all the levels of the tree are filled completely except the lowest
level nodes which are filled from as left as possible.

A heap is a complete binary tree that satisfies the heap property,
where any given node is:
- Always greater than its child node/s and the key of the root node
is the largest among all other nodes. - Max heap property,
- Always smaller than the child nodes/s and the key of the root node
is the smallest among all other nodes. - Min heap property,

Example max-heap
    9
 5     4
1 3   2

Example min-heap
    1
 2     3
4 5   9

Key operations include:
- Heapify
- Insert
- Delete
- Peek

To be honest, I doubt this will come up, so I'll leave it as just
the implementation below, rather than explain each one.

Heaps are used in:
- The implementation of a priority queue
- Dijkstra's algorithm
- Heap sort
"""

# Max-Heap data structure in Python

def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2 
    
    if l < n and arr[i] < arr[l]:
        largest = l
    
    if r < n and arr[largest] < arr[r]:
        largest = r
    
    if largest != i:
        arr[i],arr[largest] = arr[largest],arr[i]
        heapify(arr, n, largest)

def insert(array, newNum):
    size = len(array)
    if size == 0:
        array.append(newNum)
    else:
        array.append(newNum);
        for i in range((size//2)-1, -1, -1):
            heapify(array, size, i)

def deleteNode(array, num):
    size = len(array)
    i = 0
    for i in range(0, size):
        if num == array[i]:
            break
        
    array[i], array[size-1] = array[size-1], array[i]

    array.remove(num)
    
    for i in range((len(array)//2)-1, -1, -1):
        heapify(array, len(array), i)
    
arr = []

insert(arr, 3)
insert(arr, 4)
insert(arr, 9)
insert(arr, 5)
insert(arr, 2)

print ("Max-Heap array: " + str(arr))

deleteNode(arr, 4)
print("After deleting an element: " + str(arr))