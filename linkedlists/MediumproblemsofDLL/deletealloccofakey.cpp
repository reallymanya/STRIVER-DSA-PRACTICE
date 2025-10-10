#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
       prev = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev= nullptr;
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

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == k){
            if(temp == head){
                head = head->next;
            }

           Node* nextNode = temp->next;
           Node* prevNode = temp->prev;

           if(nextNode != NULL) nextNode->prev = prevNode;
           if(prevNode != NULL) prevNode->next = nextNode;

           free(temp);

           temp = nextNode;
        }
        else{
            temp = temp->next;
        }
       
    }
     return head;
}


int main(){
    vector<int> arr = {2,5,8,7,5,4};
    Node* head = convertArr2DLL(arr);
    print(head);

    Node* dell = deleteAllOccurrences(head,5);
    print(dell);
}

