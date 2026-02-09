struct Node{
    int key,value,cnt;
    Node* next;
    Node* prev;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        cnt = 1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node* node){
        Node *nextNode = node->next;
        Node *prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        size--;
    }
};

class LFUCache {
    
    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    
    void updateFreqList(Node* node){

        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        minFreq++;

        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt+1];
        }

        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;

    }
    int get(int key) {
        if(keyNode.find(key) != keyNode.end())
        {
        Node* node = keyNode[key];
        int val = node->value;
        updateFreqList(node);
        return val;
    } 
    return -1;
   }
    
    void put(int key, int value) {
        if(maxSizeCache == 0)
        return;

        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }

        else{
            if(maxSizeCache == currSize){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);

                freqListMap[minFreq]->removeNode(
                    list->tail->prev
                );

                currSize--;
            }

            currSize++;

            minFreq = 1;

            List* listfreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listfreq = freqListMap[minFreq];
            }

            Node* node = new Node(key,value);
            listfreq->addFront(node);

            keyNode[key] = node;

            freqListMap[minFreq] = listfreq;
        }
    }
};
