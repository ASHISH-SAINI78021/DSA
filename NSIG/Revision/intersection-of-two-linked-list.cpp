class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while (temp1 != temp2){
            if (temp1 == NULL){
                temp1 = headB;
            }
            else temp1 = temp1->next;

            if (temp2 == NULL){
                temp2 = headA;
            }
            else temp2 = temp2->next;
        }

        return temp1;
    }
};

// 4 -> 1 -> 8 -> 4 -> 5 -> end -> 5 -> 6 -> 1 -> 8
// 5 -> 6 -> 1 -> 8-> 4 -> 5 -> end -> 4 -> 1 -> 8