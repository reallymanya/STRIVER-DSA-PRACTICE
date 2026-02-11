class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

       ListNode* prev = dummy;
       ListNode* temp = head;
       
       while(temp != nullptr){
        if(temp->next != nullptr && temp->val == temp->next->val){
            int value = temp->val;

            while(temp != nullptr && temp->val == value){
                ListNode* duplicate = temp;
                temp = temp->next;
                delete duplicate;
            }

            prev->next = temp;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
       }
       return dummy->next;
    }
};
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};