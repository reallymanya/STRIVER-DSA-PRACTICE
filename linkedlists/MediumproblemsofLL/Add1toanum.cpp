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


int addHelper(Node* temp){
    if(temp == NULL) return 1;

    int carry = addHelper(temp->next);
    // temp->data = temp->data + carry;
    // if(temp->data < 10) return 0;
    // temp->data = 0;
    // return 1;

    int sum = temp->data + carry;
    temp->data = sum % 10;
    return sum/10;
}
Node *addOne(Node *head)
{
    // Write Your Code Here.
    int carry = addHelper(head);
    if(carry == 1){
       Node* newNode = new Node(1);
       newNode->next = head;
       return newNode;
    }
    return head;
}


int main(){
    vector<int> num1Digits = {4,5,9,9};
    Node* head = convertArr2LL(num1Digits);


    Node* sum = addOne(head);
    print(sum);

}