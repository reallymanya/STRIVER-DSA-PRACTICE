#include <iostream>
#include <vector>
#include <queue>
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

Node* reverse(Node* head){
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* findKthNode(Node* temp, int K){
    K-=1;
    while(temp!= NULL && K>0){
        K--;
        temp = temp->next;
    }
    return temp;
}
Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node* temp = head;
    Node* prevNode = NULL;

    while(temp != NULL){
        Node* KthNode = findKthNode(temp,k);

        if(KthNode == NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }

        Node* nextNode = KthNode->next;
        KthNode->next = NULL;
        reverse(temp);

        if(temp == head){
            head = KthNode;
        }
        else
        prevNode->next = KthNode;

        prevNode = temp;
        temp = nextNode;
    }

    return head;
}

int main(){
    vector<int> num1Digits = {4,5,7,9,8,5};
    Node* head = convertArr2LL(num1Digits);

    cout << "Original list: ";
    print(head);

    int k = 3;
    head = kReverse(head, k);

    cout << "After reversing in groups of " << k << ": ";
    print(head);

    // free memory
    Node* cur = head;
    while(cur){
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }

    return 0;
}