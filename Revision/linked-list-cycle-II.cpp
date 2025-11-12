class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL){
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;

            if (slow == fast){
                slow = head;
                while (slow != fast){
                    slow = slow->next
                    fast = fast->next
                }

                return slow;
            }
        }

        return NULL
    }
}