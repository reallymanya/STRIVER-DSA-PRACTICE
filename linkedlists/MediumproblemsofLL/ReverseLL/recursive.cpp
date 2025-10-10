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

Node *ReverseLL(Node *head)
{
   if(head == NULL || head->next == NULL)
   return head;

   Node* newHead = ReverseLL(head->next);

   Node* front = head->next;
   front->next = head;
   head->next = NULL;

   return newHead;
}


int main(){
    vector<int> num1Digits = {4,5,9,8};
    Node* head = convertArr2LL(num1Digits);

    head = ReverseLL(head);
    print(head);

}