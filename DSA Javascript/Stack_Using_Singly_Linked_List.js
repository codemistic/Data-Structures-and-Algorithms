// //Stack using linkedlist
// function stackUsingLL(){
//   //Node 
//   let Node = function(elm){
//     this.element = elm;
//     this.next = null;
//   }
  
//   //To keep track of the size  
//   let length = 0;
  
//   //To keep track of the list
//   let head = null;
  
//   //Push data in the stack
//   this.push = function(elm){
//     //Create a new node
//     let node = new Node(elm),
//     current;
    
//     //Add the new node at the top
//     current = head;
//     node.next = current;
//     head = node;
    
//     length++;
//   }
  
//   //Pop the item from the stack
//   this.pop = function(){
//     let current = head;
    
//     //If there is item then remove it 
//     //and make the next element as the first
//     if(current){
//       let elm = current.element;
//       current = current.next;
//       head = current;
//       length--;
//       return elm;
//     }
    
//     return null;   
//   }
  
//   //Return the first element in the stack
//   this.peek = function(){    
//     if(head){    
//       return head.element;
//     }

//     return null;
//   }
  
//   //Convert the stack to an array
//   this.toArray = function(){
//     let arr = [];
//     let current = head;
//     while(current){
//       arr.push(current.element);
//       current = current.next;
//     }
    
//     return arr;
//   }
  
//   //Check if stack is empty
//   this.isEmpty = function(){
//     return length === 0;
//   }
  
//   //Return the size of the stack
//   this.size = function(){
//     return length;
//   }
  
//   //Clear the stack
//   this.clear = function(){
//     head = null;
//     length = 0;
//   }
  
// }
class Node {
  constructor(element) {
    this.element = element;
    this.next = null;
  }
}

class Stack {
  constructor() {
    this.head = null; // Top of stack
    this.length = 0;  // Stack size
  }

  // Push element onto the stack
  push(element) {
    const node = new Node(element);
    node.next = this.head;
    this.head = node;
    this.length++;
  }

  // Pop the top element from the stack
  pop() {
    if (this.isEmpty()) return null; // Handle empty stack

    const poppedElement = this.head.element;
    this.head = this.head.next;
    this.length--;

    return poppedElement;
  }

  // Peek at the top element without removing it
  peek() {
    return this.head ? this.head.element : null;
  }

  // Convert stack to an array (from top to bottom)
  toArray() {
    let arr = [];
    let current = this.head;
    while (current) {
      arr.push(current.element);
      current = current.next;
    }
    return arr;
  }

  // Check if the stack is empty
  isEmpty() {
    return this.length === 0;
  }

  // Return the size of the stack
  size() {
    return this.length;
  }

  // Clear the stack
  clear() {
    this.head = null;
    this.length = 0;
  }
}
