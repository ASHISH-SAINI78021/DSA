class Solution {
public:
    ListNode* middle(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }

        if (prev){
            prev->next = NULL;
        }

        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* l1 = left;
        ListNode* l2 = right;
        ListNode* t = dummy;

        while (l1 && l2){
            if (l1->val > l2->val){
                t->next = l2;
                t = t->next;
                l2 = l2->next;
            }
            else {
                t->next = l1;
                t = t->next;
                l1 = l1->next;
            }
        }

        while (l1){
            t->next = l1;
            t = t->next;
            l1 = l1->next;
        }

        while (l2){
            t->next = l2;
            t = t->next;
            l2 = l2->next;
        }

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* mid = middle(head);
        ListNode* left = head;

        left = sortList(left);
        ListNode* right = sortList(mid);

        return merge(left, right);
    }
};