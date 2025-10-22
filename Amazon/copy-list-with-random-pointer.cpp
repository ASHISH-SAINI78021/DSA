/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head){
            return head;
        }
        Node* curr = head;
        while (curr){
            Node* copy = new Node(curr->val);
            Node* next = curr->next;
            curr->next = copy;
            copy->next = next;
            curr = next;
        }

        curr = head;
        
        while (curr){
            Node* copy = curr->next;
            if (curr->random){
                copy->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // step 3
        curr = head;
        Node* newHead = head->next;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            if (copy->next)
                copy->next = copy->next->next;
            curr = curr->next;
        }

        return newHead;
    }
};