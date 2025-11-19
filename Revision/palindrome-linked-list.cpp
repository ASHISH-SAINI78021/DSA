class Solution {
public:
    ListNode* solve(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while (fast != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast){
                fast = fast->next;
            }
        }

        return slow;
    }
    ListNode* solve2(ListNode* &temp){
        ListNode* curr = temp;
        ListNode* prev = NULL;
        
        while (curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode* mid = solve(head);
        mid = solve2(mid);
        
        while (mid != NULL){
            if (head->val != mid->val) return false;
            head = head->next;
            mid = mid->next;
        }

        return true;
    }
};