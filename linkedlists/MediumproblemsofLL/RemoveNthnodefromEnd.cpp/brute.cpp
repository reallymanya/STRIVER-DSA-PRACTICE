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

Node* DeleteNthNodefromEnd(Node* head, int N) {
    if (head == NULL) {
        return NULL;
    }

    int cnt = 0;
    Node* temp = head;

    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    if (cnt == N) {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }

    
    int res = cnt - N;
    temp = head;

    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

int main(){
    vector<int> num1Digits = {1,2,3,4,5};
    Node* head = convertArr2LL(num1Digits);


    head = DeleteNthNodefromEnd(head,3);
    print(head);

}





