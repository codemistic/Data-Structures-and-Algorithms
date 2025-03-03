class Node {
    constructor(element) {
        this.element = element;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
        this.tail = null; // Optimization: Keep track of tail for O(1) append
        this.size = 0;
    }

    // Add an element at the end (O(1) with tail pointer)
    add(element) {
        const node = new Node(element);
        if (!this.head) {
            this.head = this.tail = node;
        } else {
            this.tail.next = node;
            this.tail = node;
        }
        this.size++;
    }

    // Insert at a specific index (O(n))
    insertAt(element, index) {
        if (index < 0 || index > this.size) {
            console.log("Invalid index");
            return;
        }
        const node = new Node(element);
        if (index === 0) {
            node.next = this.head;
            this.head = node;
            if (!this.tail) this.tail = node;
        } else {
            let prev = this.getAt(index - 1);
            node.next = prev.next;
            prev.next = node;
            if (!node.next) this.tail = node;
        }
        this.size++;
    }

    // Remove element at given index (O(n))
    removeFrom(index) {
        if (index < 0 || index >= this.size) {
            console.log("Invalid index");
            return null;
        }
        let removedElement;
        if (index === 0) {
            removedElement = this.head.element;
            this.head = this.head.next;
            if (!this.head) this.tail = null;
        } else {
            let prev = this.getAt(index - 1);
            removedElement = prev.next.element;
            prev.next = prev.next.next;
            if (!prev.next) this.tail = prev;
        }
        this.size--;
        return removedElement;
    }

    // Remove by value (O(n))
    removeElement(element) {
        if (!this.head) return null;
        if (this.head.element === element) {
            return this.removeFrom(0);
        }
        let prev = this.head;
        while (prev.next && prev.next.element !== element) {
            prev = prev.next;
        }
        if (!prev.next) return null;
        if (prev.next === this.tail) this.tail = prev;
        const removedElement = prev.next.element;
        prev.next = prev.next.next;
        this.size--;
        return removedElement;
    }

    // Get node at index (O(n))
    getAt(index) {
        if (index < 0 || index >= this.size) return null;
        let current = this.head;
        for (let i = 0; i < index; i++) {
            current = current.next;
        }
        return current;
    }

    // Get index of element (O(n))
    indexOf(element) {
        let current = this.head, index = 0;
        while (current) {
            if (current.element === element) return index;
            current = current.next;
            index++;
        }
        return -1;
    }

    // Check if empty (O(1))
    isEmpty() {
        return this.size === 0;
    }

    // Get size (O(1))
    size_of_list() {
        return this.size;
    }

    // Print list (O(n))
    printList() {
        let elements = [];
        let current = this.head;
        while (current) {
            elements.push(current.element);
            current = current.next;
        }
        console.log(elements.join(" "));
    }
}

// Test the optimized LinkedList
const ll = new LinkedList();

console.log(ll.isEmpty()); // true
ll.add(10);
ll.printList(); // 10
console.log(ll.size_of_list()); // 1

ll.add(20);
ll.add(30);
ll.add(40);
ll.add(50);
ll.printList(); // 10 20 30 40 50

console.log("Removed:", ll.removeElement(50)); // 50
ll.printList(); // 10 20 30 40

console.log("Index of 40:", ll.indexOf(40)); // 3
ll.insertAt(60, 2);
ll.printList(); // 10 20 60 30 40

console.log("Removed at index 3:", ll.removeFrom(3)); // 30
ll.printList(); // 10 20 60 40
