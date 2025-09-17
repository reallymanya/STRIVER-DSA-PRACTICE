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

Node* insertvalbeforeX(Node* head, int val, int x){
  if(head == NULL){
   return NULL;
  }

  if(head->data == x)
  return new Node(val,head);

  Node* temp = head;
  while(temp->next != NULL){

    if(temp->next->data == x){
        Node* n = new Node(val,temp->next);
        temp->next = n;
         return head;
        break;
    }
    temp = temp->next;
  }
  cout << "Element " << x << " not found in the list.\n";
    return head;
}


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    print(head);
    head = insertvalbeforeX(head,3,1);
    print(head);
}