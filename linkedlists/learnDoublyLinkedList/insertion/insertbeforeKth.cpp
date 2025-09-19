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

Node* insertbeforeK(Node* head, int k, int val){
    if(k == 1)
    return insertBeforeHead(head,val);

    Node* temp = head;
    int cnt = 0;

    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newnode = new Node(val,temp,prev);
    prev->next = newnode;
    temp->back = newnode;

    return head;
}
int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2DLL(arr);
    print(head);

    head = insertbeforeK(head,4,9);
    print(head);
}