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

Node* insertAtK(Node* head, int val, int K){
  if(head == NULL){
    if(K == 1){
        return new Node(val);
    }else return NULL;
  }

  if(K == 1)
  return new Node(val,head);

  int cnt = 0;
  Node* temp = head;
  while(temp != NULL){
    cnt++;

    if(cnt == K-1){
        Node* x = new Node(val,temp->next);
        temp->next = x;
        break;
    }
    temp = temp->next;
  }
  return head;
}


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    print(head);
    head = insertAtK(head,3,4);
    print(head);
}