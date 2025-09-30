/*struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};*/

Node* reverseList(Node* head) {
    if (head == NULL) return head;
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