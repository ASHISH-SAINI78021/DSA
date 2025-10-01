/*struct Node {
    int val;
    struct Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};*/

Node* reverseSegment(Node* head, int L, int R) {
    if (!head || L == R) return head;

    // dummy simplifies handling when L = 1
    Node dummy(0);
    dummy.next = head;
    Node* prevStart = &dummy;

    // step 1: move prevStart to node just before L
    for (int i = 1; i < L; i++) {
        prevStart = prevStart->next;
    }

    // step 2: start of sublist to reverse
    Node* start = prevStart->next;
    Node* curr = start->next;

    // step 3: reverse [L..R] in-place
    for (int i = 0; i < R - L; i++) {
        Node* next = curr->next;
        curr->next = prevStart->next;
        prevStart->next = curr;
        curr = next;
    }

    // step 4: reconnect
    start->next = curr;

    return dummy.next;
}
