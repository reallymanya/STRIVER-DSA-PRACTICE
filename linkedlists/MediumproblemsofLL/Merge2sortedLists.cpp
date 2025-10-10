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

Node* sortTwoLists(Node* first, Node* second)
{
    // Write your code here.
    Node* t1 = first;
    Node* t2 = second;

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(t1!= NULL && t2!= NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1=t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2=t2->next;
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    return dummyNode->next;
}

   

int main(){
    vector<int> num1Digits = {4,5,7,9};
    vector<int> num2Digits = {2,3};
    Node* head = convertArr2LL(num1Digits);
    Node* headd = convertArr2LL(num2Digits);

    Node* newhead = sortTwoLists(head, headd);
    print(newhead);

}

