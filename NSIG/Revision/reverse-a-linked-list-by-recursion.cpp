class Solution {
public:
    ListNode* reversedList(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = reversedList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }
    // 1 -> 2 -> 3
    
    // 3-> 2
    // 2->NULL;

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        head = reversedList(head);

        return head;
    }
};