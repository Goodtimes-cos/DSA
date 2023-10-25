class Queue:
    def __init__(self, size):
        self.queue = []
        self.front = 0
        self.rear = 0
        self.capacity = size

    def enqueue(self, value):
        if self.rear < self.capacity:
            self.queue.append(value)
            self.rear += 1
    
    def dequeue(self):
        if self.front != self.rear:
            self.front += 1
            
    
    def display(self):
        print(self.front, self.rear)
        for i in range(self.front, self.rear):
            print(self.queue[i])

    def getFront(self):
        print(self.queue[self.front])

q = Queue(4)
q.display()
print("=================\n")
q.enqueue(4)
q.enqueue(5)
q.enqueue(6)
q.enqueue(7)
q.enqueue(8)
q.display()
print("=================\n")
q.dequeue()
q.dequeue()
q.display()
print("=================\n")