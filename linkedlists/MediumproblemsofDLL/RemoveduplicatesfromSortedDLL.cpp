#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        prev = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *convertArr2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node * removeDuplicates(Node *head)
{
    // Write your code here
     Node* temp = head;
        while(temp != NULL && temp->next != NULL){
          Node* nextNode = temp->next;
            while(nextNode != NULL && nextNode->data == temp->data){
               Node* duplicate = nextNode;
                nextNode = nextNode->next;
                free(duplicate);
            }
            temp->next = nextNode;
            if(nextNode) nextNode->prev = temp;
            temp = temp->next;
        }
        return head;
}

int main()
{
    vector<int> arr = {1,1,2,3,3,4};
    Node *head = convertArr2DLL(arr);

head = removeDuplicates(head);
print(head);

return 0;
}


