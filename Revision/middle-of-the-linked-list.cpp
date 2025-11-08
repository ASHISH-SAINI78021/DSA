class Solution {
public:
    int length(ListNode* temp){
        int len = 0;
        while (temp != NULL){
            len++;
            temp = temp->next;
        }

        return len;
    }
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) return head;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL){
            fast = fast->next;
            if (fast){
                fast = fast->next;
            }
            prev = slow;
            slow = slow->next;
        }

        int n = length(head);

        return (n & 1) ? prev : slow;
    }
};