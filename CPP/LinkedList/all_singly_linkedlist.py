class Node:
    def __init__(self,data):
        self.data = data    # here nodes data is data
        self.ref = None     # it stores the refrence of none or NULL

# now to link this individual node
class LinkedList:
    def __init__(self):
        self.head = None   #this is the empty linked list (initializing linked list)
    
    # traversing the LL
    def print_LL(self):
        if self.head==None:
            print("Linked list is empty")
        else:
            n = self.head
            while n!=None:
                print(n.data , end=" ")
                n = n.ref  

    # adding new node at beginning of LL
    def add_beginning(self,data):
        new_node = Node(data)   # creating a new node from node class  ## here a node will be created having some data(i.e. the data field) and link field is Null 
        new_node.ref = self.head
        self.head = new_node

    # add at the end            
    def add_end(self,data):
        new_node = Node(data)
        if self.head == None :
            self.head = new_node
        else: 
            n = self.head
            while n.ref!=None:  # we are using this while loop to go to the last node
                n = n.ref
            n.ref = new_node

    # adding after a given node        
    def add_after(self,data,x):
        n = self.head
        while n!=None:
            if x==n.data:
                break
            n = n.ref
        if n==None:
            print("Node is not present in Linked List")
        else:
            new_node = Node(data)
            new_node.ref = n.ref 
            n.ref = new_node

    #adding before given node
    def add_before(self,data,x):
        # if linked list is empty
        if self.head==None:
            print("LL is empty")
            return
        # if x is first node    
        if self.head.data==x:
            new_node = Node(data)  
            new_node.ref = self.head
            self.head = new_node
            return
        # rest cases
        n = self.head
        while n.ref!=None:
            if n.ref.data==x:
                break
            n = n.ref
        if(n.ref==None):    
            print("x is not in LL")
        new_node = Node(data)
        new_node.ref = n.ref
        n.ref = new_node    

    # inserting element in empty LL
    def insert_when_empty(self,data):
        if self.head==None:
            new_node = Node(data)
            self.head=new_node
        else:
            print("LL is not empty")    

    # deletion at the beginning
    def delete_beginning(self):
        if self.head!=None:
            self.head = self.head.ref
        else:
            print("LL is empty, we cannot delete first node")

    # deletion at the end
    def delete_end(self):
        if self.head==None:
            print("LL is empty, we cannot delete last node") 
        elif self.head.ref==None:  # when only 1 node is present
            self.head = None
        elif self.head!=None:
            n = self.head
            while n!=None:               # or directly we can take while n.ref.ref!=None:
                if n.ref.ref == None:                                       #  n = n.ref
                    break
                n = n.ref
            n.ref = None   

    # deletion of given value            
    def delete_given(self,x):
        if self.head==None:
            print("LL is empty, we cannot delete given node") 
        elif x==self.head.data:
            self.head = self.head.ref
        elif self.head!=None:
            n = self.head
            while n.ref!=None:      # here we took n.ref because when we reach the last node (jab hum n!=none lete) there n is not equal to none toh jab hum if condition ke n.ref.data ko check karenge toh waha n.ref is none toh none.data is not defined. issliye hum last node pe hi loop break kr rahe.
                if n.ref.data==x:
                    break
                n = n.ref
            if n.ref==None:
                print("Given node is not present in LL")
            else:        
                n.ref = n.ref.ref       

LL1 = LinkedList()
LL1.add_beginning(3)
LL1.add_beginning(24)
LL1.add_end(52)
LL1.add_beginning(66)
LL1.add_end(43)
LL1.delete_given(20)
LL1.delete_given(52)
LL1.print_LL()