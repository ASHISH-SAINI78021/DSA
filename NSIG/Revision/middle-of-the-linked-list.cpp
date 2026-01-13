class Solution {
public:
    int length(ListNode* head){
        int len = 0;
        while (head != NULL){
            head = head->next;
            len++;
        }

        return len;
    }
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        int len = length(head);
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }

        return (len % 2) ? prev : slow;
    }
};