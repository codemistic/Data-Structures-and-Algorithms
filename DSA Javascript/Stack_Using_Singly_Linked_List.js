class StackUsingLL {
  constructor() {
    this.head = null;
    this.length = 0;
  }

  // Node class
  class Node {
    constructor(element) {
      this.element = element;
      this.next = null;
    }
  }

  // Push an element onto the stack
  push(element) {
    const node = new Node(element);
    node.next = this.head;
    this.head = node;
    this.length++;
  }

  // Pop an element from the stack
  pop() {
    if (!this.head) return null;
    const element = this.head.element;
    this.head = this.head.next;
    this.length--;
    return element;
  }

  // Get the top element of the stack
  peek() {
    return this.head ? this.head.element : null;
  }

  // Convert stack to an array
  toArray() {
    const arr = [];
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

  // Get stack size
  size() {
    return this.length;
  }

  // Clear the stack
  clear() {
    this.head = null;
    this.length = 0;
  }
}

// Example usage
const stack = new StackUsingLL();
stack.push(10);
stack.push(20);
console.log(stack.pop()); // 20
console.log(stack.peek()); // 10
console.log(stack.toArray()); // [10]
