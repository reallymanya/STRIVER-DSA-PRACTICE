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

Node *findtail(Node *head)
{
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    return tail;
}
vector<pair<int, int>> findPairs(Node *head, int k)
{
    // Write your code here.
    vector<pair<int, int>> ans;
    if (head == NULL)
        return ans;

    Node *left = head;
    Node *right = findtail(head);

    while (left->data < right->data)
    {
        if (left->data + right->data == k)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < k)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 1, 7, 5, 4};
    sort(arr.begin(), arr.end());
    Node *head = convertArr2DLL(arr);

    vector<pair<int, int>> pairs = findPairs(head, 5);

    for (const auto &p : pairs)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    return 0;
}
