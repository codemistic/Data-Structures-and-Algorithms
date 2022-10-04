# PYTHON PROGRAM TO CREATE A CIRCULAR QUEUE

class Queue:
    def __init__(self,maxsize):
        self.items = maxsize*[None]
        self.maxsize=maxsize
        self.start=-1
        self.top=-1
     
    def __str__(self):
        values=[str(x) for x in self.items]
        return ' '.join(values)



    # to check if queue is full
    def isFull(self):
        if self.top+1==self.start:
            return True
        elif self.start ==0 and self.top+1==self.maxsize:
            return True
        else:
            return False



    # to check if queue is empty
    def isEmpty(self):
        if self.top ==-1:
            return True
        else:
            return False



    # insert elements
    def Enqueue(self,value):
        if self.isFull():
            return "queue is full"
        else:
            if self.top+1==self.maxsize:
                self.top=0
            else:
                self.top+=1
                if self.start==-1:
                    self.start=0
            self.items[self.top]=value
            return "element inserted"



    def dequeue(self):
        if self.isEmpty():
            return "there is no element in queue"
        else:
            firstElement = self.items[self.start]
            start = self.start
            if self.start ==self.top:
                self.start=-1
                self.top=-1
            elif self.start+1==self.maxsize:
                self.start=0
            else:
                self.start+=1
            self.items[start]=None
            return firstElement



    # peek()
    def peek(self):
        if self.isEmpty():
            return "no element in queue"
        else:
            return self.items[self.start]



    #delete entire queue
    def delete(self):
        self.items =self.maxsize*[None]
        self.top=-1
        self.start=-1

