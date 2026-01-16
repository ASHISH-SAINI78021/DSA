class Solution {
public:
    int length(ListNode* head){
        int len = 0;
        while (head != NULL){
            len++;
            head = head->next;
        }

        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0){
            return head;
        }

        int n = length(head);
        k = k % n;
        k = n - k;

        if (k == n) return head;

        ListNode* temp = head;
        int i = 1;
        // cout << k << endl;
        while (temp != NULL && i < k){
            i++;
            temp = temp->next;
        }

        // cout << i << endl;
        
        ListNode* newHead = temp->next;
        temp->next = NULL;
        ListNode* tail = newHead;
        while (tail != NULL && tail->next != NULL){
            tail = tail->next;
        }
        if (tail) tail->next = head;

        return newHead;
    }
};