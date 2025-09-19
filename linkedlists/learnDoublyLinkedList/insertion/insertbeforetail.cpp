#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
Node* head = new Node(arr[0]);
Node* prev = head;
for(int i = 1; i<arr.size(); i++){
    Node* temp = new Node(arr[i],nullptr,prev);
    prev->next = temp;
    prev = temp;
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


Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val,head,nullptr);
    head->back = newHead;
    return newHead;
}


//my logic
Node* insertBeforeTail(Node* head, int val){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* tail = temp->next;
    Node* newnode = new Node(val);
    newnode->back = temp;
    newnode->next = tail;
    temp->next = newnode;
    tail->back = newnode;

    return head;
}

//striver
Node* insertBeforeTaill(Node* head, int val){
    if(head->next == NULL){
        return insertBeforeHead(head,val);
    }

    Node* tail = head;
    while(tail->next != NULL){
        tail= tail->next;
    }
    Node* prev = tail->back;
    Node* newnode = new Node(val,tail,prev);
   
    prev->next = newnode;
    tail->back = newnode;

    return head;
}


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2DLL(arr);
    print(head);

    head = insertBeforeTaill(head,1);
    print(head);
}