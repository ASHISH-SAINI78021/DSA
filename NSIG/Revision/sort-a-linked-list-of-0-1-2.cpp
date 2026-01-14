class Solution {
  public:
    Node* segregate(Node* head) {
        if (head == NULL || head->next == NULL) return head;
        Node* zeroHead = new Node(0);
        Node* zero = zeroHead;
        Node* oneHead = new Node(0);
        Node* one = oneHead;
        Node* twoHead = new Node(0);
        Node* two = twoHead;
        
        Node* temp = head;
        while (temp != NULL){
            if (temp->data == 0){
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1){
                one->next = temp;
                one = one->next;
            }
            else {
                two->next = temp;
                two = two->next;
            }
            
            temp = temp->next;
        }
        
        if (zeroHead->next != NULL && oneHead->next != NULL){
            zero->next = oneHead->next;
            one->next = twoHead->next;
            two->next = NULL;
            return zeroHead->next;
        }
        else if (oneHead->next == NULL){
            zero->next = twoHead->next;
            two->next = NULL;
            return zeroHead->next;
        }
        else if (zeroHead->next == NULL){
            one->next = twoHead->next;
            two->next = NULL;
            return oneHead->next;
        }
        
        return zeroHead->next;
    }
};