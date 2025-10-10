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

Node* DeleteNthNodefromEnd(Node* head, int N) {
    if (head == NULL) {
        return NULL;
    }

    Node* fast = head;
    Node* slow = head;

    for(int i = 0; i<N;i++){
        fast = fast->next;
    }

    if(fast == NULL){
    Node* newhead = head->next;
    delete(head);
    return newhead;
    }

    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete (delNode);
    return head;
}

int main(){
    vector<int> num1Digits = {1,2,3,4,5};
    Node* head = convertArr2LL(num1Digits);


    head = DeleteNthNodefromEnd(head,3);
    print(head);

}





