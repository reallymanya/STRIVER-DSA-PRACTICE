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

Node* removeEl(Node* head, int el){
    if(head == NULL) return head;
   if(head->data == el){
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}



int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);
    print(head);
    head = removeEl(head,8);
    print(head);
}