#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
        child = nullptr;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        child = nullptr;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

// vertical conv
Node *convertArrToLinkedList(vector<int> &arr)
{
    if (arr.size() == 0)
        return NULL;

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->child = newNode;
        temp = temp->child;
    }
    return head;
}

Node *flattenLinkedList(Node *head)
{
    vector<int> arr;
    Node *temp = head;

    while (temp != NULL)
    {
        Node *t2 = temp;
        while (t2 != NULL)
        {
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    head = convertArrToLinkedList(arr);
    return head;
}

int main()
{
    // build a sample multilevel list:
    // 5 -> 10 -> 19 -> 28
    // |     |     |     |
    // 7     20    22    35
    // |           |
    // 8           50
    // |
    // 30
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next->child = new Node(20);

    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next->child = new Node(35);

    // flatten and print
    Node *flat = flattenLinkedList(head);
    print(flat);

    return 0;
}