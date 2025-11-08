class Solution {
public:
    int length(ListNode* temp){
        int len = 0;
        while (temp != NULL){
            len++;
            temp = temp->next;
        }

        return len;
    }
    void deleteFromHead(ListNode* &head){
        if (head == NULL) return ;
        else {
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void deleteFromEnd(ListNode* &head){
        if (head == NULL) return ;
        else {
            ListNode* temp = head;
            ListNode* prev = NULL;
            while (temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }
    }
    void deleteFromPosition(ListNode* &head, int n, int &len){
        if (n == 1){
            deleteFromHead(head);
            return ;
        }
        else if (n == len){
            deleteFromEnd(head);
            return ;
        }
        else {
            int i = 1;
            ListNode* prev = NULL;
            ListNode* temp = head;
            while (i < n){
                prev = temp;
                temp = temp->next;
                i++;
            }

            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        int len = length(head);
        deleteFromPosition(head, len - n + 1, len);

        return head;
    }
};