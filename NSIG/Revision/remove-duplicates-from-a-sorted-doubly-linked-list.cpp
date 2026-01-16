class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        if (head == NULL || head->next == NULL) return head;
        struct Node* temp = head;
        while (temp != NULL && temp->next != NULL){
            if (temp->data == temp->next->data){
                struct Node* nextNode = temp->next;
                while (nextNode != NULL && nextNode->data == temp->data){
                    struct Node* duplicate = nextNode;
                    nextNode = nextNode->next;
                    delete duplicate;
                }
                temp->next = nextNode;
                if (nextNode != NULL) nextNode->prev = temp;
            }
            temp = temp->next;
        }
        
        return head;
    }
};