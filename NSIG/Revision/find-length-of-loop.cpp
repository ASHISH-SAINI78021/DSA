class Solution {
  public:
    int lengthOfLoop(Node *head) {
        if (head == NULL || head->next == NULL) return 0;
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            if (slow == fast){
                slow = head;
                while (slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                break ;
            }
        }
        
        if (fast == NULL) return 0;
        
        int len = 1;
        Node* temp = slow->next;
        while (temp != slow){
            len++;
            temp = temp->next;
        }
        
        
        return len;
    }
};