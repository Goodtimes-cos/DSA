# Singly Linked List Node
class ListNode:
    def __init__(self, val, next_node=None):
        self.val = val
        self.next = next_node

# Implementation for Singly Linked List
class LinkedList:
    def __init__(self):
        # Init the list with a 'dummy' node which makes 
        # removing a node from the beginning of list easier.
        self.head = ListNode(-1)
        self.tail = self.head
    
    def get(self, index: int) -> int:
        curr = self.head.next # So current is the pointer of where we are
        i = 0
        while curr:
            if i == index: 
                return curr.val
            i += 1
            curr = curr.next
        return -1  # Index out of bounds or list is empty
        # I like this solution, far more elegant than mine :D

    def insertHead(self, val: int) -> None:
        new_node = ListNode(val)
        new_node.next = self.head.next
        self.head.next = new_node
        if not new_node.next:  # If list was empty before insertion
            # If our new_node doesn't have another value after, we set it to be our tail :D
            self.tail = new_node

    def insertTail(self, val: int) -> None:
        self.tail.next = ListNode(val) # We insert the tail. This isn't so hard tbh
        self.tail = self.tail.next

    def remove(self, index: int) -> bool:
        i = 0 # The worst of the algorithms, let's see if they make it easy!
        curr = self.head # We get our pointer
        while i < index and curr: # So while our location is behind our node to remove, and we have
        # a node to traverse to
            i += 1
            curr = curr.next
        
        # Remove the node ahead of curr, if we have a node, and a node after!
        if curr and curr.next:
            if curr.next == self.tail:
                self.tail = curr
            curr.next = curr.next.next # Makes sense
            return True
        return False

    def getValues(self) -> List[int]:
        curr = self.head.next # We point to beginning of our linked list
        res = []
        while curr: # While we have a node, traverse the linked list
            res.append(curr.val)
            curr = curr.next
        return res