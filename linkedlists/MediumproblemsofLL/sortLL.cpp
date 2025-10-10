#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

 Node* findMiddle(Node* head) {
       Node* slow = head;
       Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

   Node* merge2sorted(Node* list1, Node* list2) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->data < list2->data) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if (list1)
            temp->next = list1;
        else
            temp->next = list2;

        return dummy->next;
    }
    Node* sortList(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

       Node* middle = findMiddle(head);
        Node* lefthead = head;
        Node* righthead = middle->next;
        middle->next = NULL;

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        return merge2sorted(lefthead, righthead);
    }

    void print(Node* head){
    while(head != NULL){
        cout << head->data<<" ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    // Linked List: 3 2 5 4 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    print(head);

    // Sort the linked list
    head = sortList(head);

    cout << "Sorted Linked List: ";
    print(head);

    return 0;
}

                                
                            