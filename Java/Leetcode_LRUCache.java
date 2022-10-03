class LRUCache {
    Node head = new Node(0,0);
    Node tail = new Node(0,0);
    HashMap<Integer,Node> cache;
    int capacity;
    public LRUCache(int capacity) {
        head.next = tail;
        tail.prev = head;  
        cache = new HashMap<>();
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if(cache.containsKey(key)){
            Node curNode = cache.get(key); 
            remove(curNode);
            insert(curNode);
            return curNode.value;
        }else{
           return -1; 
        }
    }
    
    public void put(int key, int value) {
        if(cache.containsKey(key)){
            remove(cache.get(key));
        }
        if(cache.size() == capacity){
            remove(tail.prev);
        }
        Node newNode = new Node(key,value);
        insert(newNode);
    }
    
    private void remove(Node node){
        cache.remove(node.key);
        Node prevNode = node.prev;
        Node nextNode = node.next;
        
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }
    
    private void insert(Node node){
        Node prevMostRUN = head.next;
        head.next = node;
        node.next = prevMostRUN;
        node.prev = head;
        prevMostRUN.prev = node; 
        
        cache.put(node.key,node);
    }
}

class Node{
    int key, value;
    Node next, prev;
    Node(int key, int value){
        this.key = key;
        this.value = value;
    }
}

