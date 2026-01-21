
# creation of queue 

from calendar import c


class Queue:
    def __init__(self):
        self.items =[]

    def __str__(self):
        values=[str(x) for x in self.items]
        return ' '.join(values)

    # if the queue is empty
    def isEmpty(self):
        if self.items==[]:
            return True
        else:
            return False


    #to insert elements in a queue
    def Enqueue(self,value):
        self.items.append(value)
        return "element added successfully"


    # to remove element
    def Dequeue(self):
        if self.isEmpty():
            return "there is no element in queue"
        else:
            return self.items.pop(0)


    # peek()
    def peek(self):
        if self.isEmpty():
            return "no element in queue"
        else:
            return self.items[0]


    #delete entire queue
    def delete(self):
        self.items =None


customQueue = Queue()

print(customQueue.isEmpty())

customQueue.Enqueue(1)
customQueue.Enqueue(2)
customQueue.Enqueue(3)
customQueue.Enqueue(4)
print(customQueue)

customQueue.Dequeue()
print(customQueue)

customQueue.delete()
print(customQueue)