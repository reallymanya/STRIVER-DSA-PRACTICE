#include <iostream>
#include <vector>
#include <queue>
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

Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<pair<int,Node*>,
    vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;

    for(int i = 0; i<listArray.size();i++){
        if(listArray[i]){
            pq.push({listArray[i]->data, listArray[i]});
        }
    }

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.second -> next)
            pq.push({it.second->next->data, it.second->next});

        temp->next = it.second;
        temp = temp->next;    
    }
    return dummyNode->next;
}


int main(){
    vector<int> num1Digits = {4,5,7,9};
    vector<int> num2Digits = {2,3};
    vector<int> num3Digits = {1,6,8};
    vector<Node*> listArray;
    listArray.push_back(convertArr2LL(num1Digits));
    listArray.push_back(convertArr2LL(num2Digits));
    listArray.push_back(convertArr2LL(num3Digits));

    Node* head = mergeKLists(listArray);
    print(head);

    return 0;
}