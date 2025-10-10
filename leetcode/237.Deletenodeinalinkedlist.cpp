
void deleteNode(ListNode* node) {
       ListNode* nx=node->next;
        node->val=node->next->val;
        node->next=node->next->next;
        delete nx;
    }

// we only have access to the node were deleting not the head