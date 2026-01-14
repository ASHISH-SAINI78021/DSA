/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int middle(ListNode* &head){
        if (head == NULL){
            return 0;
        }
        int count = 1;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            count++;
        }

        return count;        
    }
    void deleteFromHead(ListNode* &head){
        if (head == NULL){
            return ;
        }
        else {
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void deleteFromEnd(ListNode* &head){
        if (head == NULL){
            return ;
        }
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
    int length(ListNode* &head){
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL){
            len++;
            temp = temp->next;
        }

        return len;
    }
    void deleteFromPosition(ListNode* &head , int n){
        if (head == NULL){
            return ;
        }

        int len = length(head);

        if (n == 1){
            deleteFromHead(head);
            return ;
        }
        if (n == len){
            deleteFromEnd(head);
            return ;
        }

        int i = 1;
        ListNode* prev = NULL;
        ListNode* temp = head;
        
        while (i < n){
            i++;
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;     
    }
    ListNode* deleteMiddle(ListNode* head) {
        int mid = middle(head);

        if (mid == NULL){
            return head;
        }

        deleteFromPosition(head , mid);

        return head;
    }   
};