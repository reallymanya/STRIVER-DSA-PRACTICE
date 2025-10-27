#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
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

void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}
Node *cloneLL(Node *head){
    Node* temp = head;
    unordered_map<Node*, Node*> mpp;

    while(temp != NULL){
        Node* newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
    
        temp = temp->next;
    }
    return mpp[head];
}

int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node* clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}
       