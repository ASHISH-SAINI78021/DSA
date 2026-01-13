class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            if (slow == fast) return true;
        }

        return false;
    }
};