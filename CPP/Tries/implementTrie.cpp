class Node {
public:
    char c;
    Node* child[26];
    bool isWord;
    
    Node(char c) {
        this -> c = c;
        isWord = false;
        
        for(int i = 0 ; i < 26 ; i++)
            child[i] = NULL;
    }
};

class Trie {
    Node* root;
    Node* getNode(string &s){
        Node* curr = root;
        for(auto &ch:s){
            if(curr -> child[ch - 97] == NULL)
                return NULL;
            curr = curr -> child[ch - 97];
        }
        
        return curr;
    }
public:
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node* curr = root;
        
        for(auto &ch:word){
            if(curr -> child[ch - 97] == NULL)
                curr -> child[ch - 97] = new Node(ch);
            curr = curr -> child[ch - 97];
        }
        
        curr -> isWord = true;
    }
    
    bool search(string word) {
        Node* reqNode = getNode(word);
        
        return reqNode && reqNode -> isWord;
    }
    
    bool startsWith(string prefix) {
        return getNode(prefix) != NULL;
    }
};

