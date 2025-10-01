/*struct Node {
	int val;
	struct Node* next;
	Node(int x){
		val = x;
		next = NULL;
	}
};*/ 

Node* reverseMSizeGroups(Node* head, int M){
    if (!head || M == 1) return head;

    Node* dummy = new Node(0); // dummy before head
    dummy->next = head;
    Node* prevGroupEnd = dummy;
    Node* curr = head;

    while (curr) {
        Node* groupStart = curr;
        Node* prev = NULL;
        Node* next = NULL;

        // reverse exactly M nodes
        for (int i = 0; i < M && curr; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // prev is now head of this reversed group
        prevGroupEnd->next = prev;
        groupStart->next = curr;
        prevGroupEnd = groupStart;
    }

    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}
