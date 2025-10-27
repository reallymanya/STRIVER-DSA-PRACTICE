#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    public:
    Node(int data1,Node* next1,Node* random1){
        data = data1;
        next = next1;
        random = random1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        random = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
Node* head = new Node(arr[0]);
Node* mover = head;
for(int i = 1; i<arr.size(); i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
}
return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data<<" ";
        head = head->next;
    }
    cout << endl;
}

void insertCopyinBetween(Node* head){
    Node* temp = head;

    while(temp != NULL){
        Node* copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
}

void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copyNode = temp->next;

        if(temp->random)
        copyNode->random = temp->random->next;

        else
        copyNode->random = NULL;

        temp = temp->next->next;
    }
}

Node* getDeepCopyList(Node* head){
    Node* temp = head;
    Node* dNode = new Node(-1);
    Node* res = dNode;

    while(temp != NULL){
        res->next = temp->next;
        temp->next = temp->next->next;
        
        res = res->next;
        temp = temp->next;
    }
    return dNode->next;
}

Node *cloneLL(Node *head){
	// Write your code here
    insertCopyinBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2LL(arr);

    // collect nodes to set random pointers
    vector<Node*> nodes;
    for (Node* cur = head; cur != nullptr; cur = cur->next) nodes.push_back(cur);

    if (nodes.size() >= 5) {
        nodes[0]->random = nodes[2]; // 1 -> 3
        nodes[1]->random = nodes[0]; // 2 -> 1
        nodes[2]->random = nodes[4]; // 3 -> 5
        nodes[3]->random = nodes[2]; // 4 -> 3
        nodes[4]->random = nodes[1]; // 5 -> 2
    }

    Node* cloned = cloneLL(head);

    cout << "Original list:\n";
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->data << " (rand: ";
        if (cur->random) cout << cur->random->data;
        else cout << "NULL";
        cout << ") -> ";
    }
    cout << "NULL\n";

    cout << "Cloned list:\n";
    for (Node* cur = cloned; cur != nullptr; cur = cur->next) {
        cout << cur->data << " (rand: ";
        if (cur->random) cout << cur->random->data;
        else cout << "NULL";
        cout << ") -> ";
    }
    cout << "NULL\n";

    // Quick deep-copy sanity check: nodes should not be the same addresses
    bool deep = true;
    Node* a = head;
    Node* b = cloned;
    while (a && b) {
        if (a == b) { deep = false; break; }
        a = a->next; b = b->next;
    }
    cout << (deep ? "Clone is a deep copy\n" : "Clone shares nodes with original\n");

    return 0;
}