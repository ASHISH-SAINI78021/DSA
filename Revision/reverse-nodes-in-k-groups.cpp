class Solution {
public:
    ListNode* reverse(ListNode* start, ListNode* end){
        ListNode* curr = start;
        ListNode* prev = NULL;
        while (curr != NULL && curr != end){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL){
            return head;
        }

        ListNode* temp = head;
        int count = 0;
        while (count < k && temp){
            count++;
            temp = temp->next;
        }

        if (count < k) return head;
        ListNode* newHead = reverse(head, temp);
        head->next = reverseKGroup(temp, k);

        return newHead;
    }
};