class Solution {
  public:
    Node *reverse(Node *head) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        
        Node* curr = head;
        Node* temp = NULL;
        
        while (curr != NULL){
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        
        head = temp->prev;
        
        return head;
    }
};