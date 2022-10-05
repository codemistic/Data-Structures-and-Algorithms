class Node:
    def __init__(self,value=None):
        self.value = value
        self.next=next

class LinkedList:
    def __init__(self):
        self.head=None

    def __iter__(self):
        curNode=self.head
        while curNode:
            yield curNode
            curNode=curNode.next

class Stack:
    def __init__(self):
        self.LinkedList=LinkedList()

    def __str__(self):
        values=[str(x.value) for x in self.LinkedList]
        return '\n'.join(values)

    def isEmpty(self):
        if self.LinkedList.head == None:
            return True
        else:
            return False

    def push(self,value):
        node=Node(value)
        node.next=self.LinkedList.head
        self.LinkedList.head = node

    #pop
    def pop(self):
        if self.isEmpty():
            print("there is no element in the stack")
        else:
            nodeValue=self.LinkedList.head.value
            self.LinkedList.head=self.LinkedList.head.next
            return nodeValue

    # peek
    def peek(self):
        if self.isEmpty():
            print("there is no element in the stack")
        else:
            nodeValue=self.LinkedList.head.value
            return nodeValue
 


    # delete entire stack
    def delete(self):
        self.list=None


customStack = Stack()
customStack.push(1)
customStack.push(2)
customStack.push(3)
print(customStack)

print("\n")
customStack.pop()
print(customStack)

print("\n")

print(customStack.peek())
print(customStack)