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

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
   
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* newTail = tail->back;
    newTail->next = NULL;
    tail->back = NULL;
    
    delete tail;
    return head;
}

Node* deleteKthelement(Node* head, int K){
    //empty
    if(head == NULL) return NULL;

    int cnt = 0;
    Node* temp = head;

    while(temp != nullptr){
        cnt++;

        if(cnt == K){
        break;
    }

    temp = temp->next;
    }

   Node* prev = temp->back;
   Node* front = temp->next;

    //single node
    if(prev == NULL && front == NULL){
        delete temp;
    }
    //delete head
    else if(prev == NULL){
        return deleteHead(head);
    }
    //delete tail
    else if(front == NULL){
        return deleteTail(head);
    }
    //any in between 
        prev->next = front;
        front->back = prev;
        temp->next = NULL;
        temp->back = NULL;
        delete temp;
    
    return head;
}
int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2DLL(arr);
    print(head);

    head = deleteKthelement(head,4);
    print(head);
}