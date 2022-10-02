#  PYTHON CODE TO DIVIDE THE LIST INTO THREE STACKS

class MultiStack:
    def __init__(self,stacksize):
        self.numberstacks=3
        self.custList=[0]*(stacksize*self.numberstacks)
        self.sizes=[0]*self.numberstacks
        self.stacksize=stacksize

    def isFull(self,stacknum):
        if self.sizes[stacknum]==self.stacksize:
            return True
        else:
            return False

    def isEmpty(self,stacknum):
        if self.sizes[stacknum]==0:
            return True
        else:
            return False

    def indexOfTop(self,stacknum):
        offset=stacknum*self.stacksize
        return offset+self.sizes[stacknum]-1
    
    def push(self,item,stacknum):
        if self.isFull(stacknum):
            return "stack is full"
        else:
            self.sizes[stacknum]+=1
            self.custList[self.indexOfTop(stacknum)]=item

    def pop(self,stacknum):
        if self.isEmpty(stacknum):
            return "stack is empty"
        else:
            value = self.custList[self.indexOfTop(stacknum)]
            self.custList[self.indexOfTop(stacknum)]=0
            self.sizes[stacknum]-=1
            return value

    def pop(self,stacknum):
        if self.isEmpty(stacknum):
            return "stack is empty"
        else:
            value = self.custList[self.indexOfTop(stacknum)]
            return value
    
