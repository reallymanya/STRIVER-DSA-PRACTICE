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



Node* merge(Node* list1, Node* list2){
	Node* dummy = new Node(-1);
	Node* res = dummy;

	while(list1 != NULL && list2 != NULL){
		if(list1->data < list2->data){
			res->child = list1;
			res = list1;
			list1 = list1->child;
		}
		else{
			res->child = list2;
			res = list2;
			list2 = list2->child;
		}
		res->next = NULL;
	}

	if(list1) res->child = list1;
	else res->child = list2;

	 if(dummy->child){
        dummy->child->next = NULL;
    }

	return dummy->child;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head == NULL || head->next == NULL)
	return head;

	Node* mergedHead = flattenLinkedList(head->next);
	return merge(head,mergedHead);
	
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