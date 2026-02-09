class LRUCache {
public:

    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val){
            this->key = key;
            this->val = val;
        }

    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
     unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node){
        Node* temp = head->next;
        node->next = temp;
        head->next = node;
        node->prev = head;
        temp->prev = node;
    }
    
    void deleteNode(Node* node){
        Node* delprev = node->prev;
        Node* delNext = node->next;
        delprev->next = delNext;
        delNext->prev = delprev;

    }
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resNode = m[key];
            deleteNode(resNode);
            addNode(resNode);
            return resNode->val;        
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            node->val = value;
            deleteNode(node);
            addNode(node);
        }
        else{
            if(m.size() == cap){
            Node* node = tail->prev;
            m.erase(node->key);
            deleteNode(node);
        }
        Node* node = new Node(key,value);
        m[key] = node;
        addNode(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */