class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != NULL && temp2 != NULL){
            if (temp1->val > temp2->val){
                ListNode* newNode = new ListNode(temp2->val);
                current->next = newNode;
                temp2 = temp2->next;
            }
            else {
                ListNode* newNode = new ListNode(temp1->val);
                current->next = newNode;
                temp1 = temp1->next;
            }
            current = current->next;
        }

        while (temp1 != NULL){
            ListNode* newNode = new ListNode(temp1->val);
            current->next = newNode;
            temp1 = temp1->next;
            current = current->next;
        }

        while (temp2 != NULL){
            ListNode* newNode = new ListNode(temp2->val);
            current->next = newNode;
            temp2 = temp2->next;
            current = current->next;
        }

        return dummy->next;
    }
};