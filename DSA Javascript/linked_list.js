class Node {
    constructor(element) {
        this.element = element;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    // Adds an element at the end of the list
    add(element) {
        const node = new Node(element);
        if (!this.head) {
            this.head = node;
            this.tail = node;
        } else {
            this.tail.next = node;
            this.tail = node;
        }
        this.size++;
    }

    // Inserts an element at a given index
    insertAt(element, index) {
        if (index < 0 || index > this.size) {
            console.log("Invalid index");
            return;
        }

        const node = new Node(element);

        if (index === 0) {
            node.next = this.head;
            this.head = node;
            if (this.size === 0) this.tail = node;
        } else {
            let prev = this.getNodeAt(index - 1);
            node.next = prev.next;
            prev.next = node;
            if (!node.next) this.tail = node;
        }
        this.size++;
    }

    // Removes an element from a specified index
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
            let prev = this.getNodeAt(index - 1);
            removedElement = prev.next.element;
            prev.next = prev.next.next;
            if (!prev.next) this.tail = prev;
        }

        this.size--;
        return removedElement;
    }

    // Removes a given element from the list
    removeElement(element) {
        if (!this.head) return -1;

        if (this.head.element === element) {
            this.head = this.head.next;
            if (!this.head) this.tail = null;
            this.size--;
            return element;
        }

        let prev = this.head;
        while (prev.next && prev.next.element !== element) {
            prev = prev.next;
        }

        if (!prev.next) return -1;

        const removedElement = prev.next.element;
        prev.next = prev.next.next;
        if (!prev.next) this.tail = prev;
        this.size--;

        return removedElement;
    }

    // Finds the index of an element
    indexOf(element) {
        let current = this.head, index = 0;
        while (current) {
            if (current.element === element) return index;
            current = current.next;
            index++;
        }
        return -1;
    }

    // Checks if the list is empty
    isEmpty() {
        return this.size === 0;
    }

    // Returns the size of the list
    size_of_list() {
        return this.size;
    }

    // Prints the list
    printList() {
        let result = [];
        let current = this.head;
        while (current) {
            result.push(current.element);
            current = current.next;
        }
        console.log(result.join(" "));
    }

    // Helper method to get the node at a specific index
    getNodeAt(index) {
        let current = this.head;
        for (let i = 0; i < index; i++) {
            current = current.next;
        }
        return current;
    }
}

// Testing the optimized LinkedList
let ll = new LinkedList();

console.log(ll.isEmpty()); // true

ll.add(10);
ll.printList(); // 10

console.log(ll.size_of_list()); // 1

ll.add(20);
ll.add(30);
ll.add(40);
ll.add(50);
ll.printList(); // 10 20 30 40 50

console.log("Is element removed? " + ll.removeElement(50)); // 50
ll.printList(); // 10 20 30 40

console.log("Index of 40: " + ll.indexOf(40)); // 3

ll.insertAt(60, 2);
ll.printList(); // 10 20 60 30 40

console.log("Is list empty? " + ll.isEmpty()); // false

console.log(ll.removeFrom(3)); // 30
ll.printList(); // 10 20 60 40
