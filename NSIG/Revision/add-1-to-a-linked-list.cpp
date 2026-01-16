class Solution {
  public:
    Node* reverseList(Node* head){
        if (head == NULL || head->next == NULL){
            return head;
        }
        Node* curr = head;
        Node* prev = NULL;
        
        while (curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    Node* addOne(Node* head) {
        if (head == NULL) return new Node(1);
        
        head = reverseList(head);
        int value = 0;
        int remainder = 0;
        int carry = 0;
        Node* temp = head;
        Node* prev = head;
        while (temp != NULL){
            if (temp == head){
                value = temp->data + carry + 1;
            }
            else {
                value = temp->data + carry;
            }
            carry = value/10;
            remainder = value%10;
            temp->data = remainder;
            if (carry == 0) break;
            prev = temp;
            temp = temp->next;
        }
        
        if (carry){
            Node* newNode = new Node(carry);
            prev->next = newNode;
        }
        
        head = reverseList(head);
        return head;
    }
};