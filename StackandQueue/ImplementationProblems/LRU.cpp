
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        Node *next;
        Node *prev;

        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node *> mpp;

    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
        head->next = node;
    }

    void deleteNode(Node *node)
    {
        Node *nextNode = node->next;
        Node *prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }

    int get(int key)
    {
        // Write your code here
        if (mpp.find(key) != mpp.end())
        {
            Node *node = mpp[key];
            deleteNode(node);
            addNode(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if (mpp.find(key) != mpp.end())
        {
            Node *node = mpp[key];
            node->val = value;
            deleteNode(node);
            addNode(node);
        }
        else
        {
            if (mpp.size() == cap)
            {
                Node *node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node *node = new Node(key, value);
            mpp[key] = node;
            addNode(node);
        }
    }
};

int main()
{
    LRUCache *cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl; // Output: 1

    cache->put(3, 3);
    cout << cache->get(2) << endl; // Output: -1

    cache->put(4, 4);
    cout << cache->get(1) << endl; // Output: -1
    cout << cache->get(3) << endl; // Output: 3
    cout << cache->get(4) << endl; // Output: 4

    delete cache;
    return 0;
}