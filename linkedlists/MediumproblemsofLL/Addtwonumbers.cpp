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

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* dummyHead = new Node(-1);
        Node* curr = dummyHead;

        Node* t1 = num1;
        Node* t2 = num2;

        int carry = 0;

        while (t1 != NULL || t2 != NULL) {
            int sum = carry;
            if (t1)
                sum = sum + t1->data;
            if (t2)
                sum = sum + t2->data;

            Node* newNode = new Node(sum % 10);
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;

            if (t1)
                t1 = t1->next;
            if (t2)
                t2 = t2->next;
        }
        if (carry) {
            Node* newNode = new Node(carry);
            curr->next = newNode;
        }
        return dummyHead->next;
}


int main(){
    vector<int> num1Digits = {4,5,9,9};
    vector<int> num2Digits = {3,5};
    Node* head = convertArr2LL(num1Digits);
    Node* headd = convertArr2LL(num2Digits);

    Node* sum = addTwoNumbers(head, headd);
    print(sum);

}