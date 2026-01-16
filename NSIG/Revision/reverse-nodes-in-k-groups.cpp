class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* end){
        ListNode* curr = head;
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
        if (head == NULL || head->next == NULL) return head;
        int count = 0;
        ListNode* temp = head;
        while (count < k && temp != NULL){
            count++;
            temp = temp->next;
        }
        if (count < k) return head;
        ListNode* newHead = reverse(head, temp);
        head->next = reverseKGroup(temp, k);

        return newHead;
    }
};