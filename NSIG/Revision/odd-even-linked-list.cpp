class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* oddHead = new ListNode(0);
        ListNode* odd = oddHead;
        ListNode* evenHead = new ListNode(0);
        ListNode* even = evenHead;

        ListNode* temp = head;
        int i = 1;
        while (temp != NULL){
            if (i & 1){
                odd->next = temp;
                odd = odd->next;
            }
            else {
                even->next = temp;
                even = even->next;
            }
            temp = temp->next;
            i++;
        }

        odd->next = evenHead->next;
        even->next = NULL;
        return oddHead->next;
    }
};