/*class Node
{
    public:
    int val;
    Node* next;
    Node* child;
    Node(int val)
    {
        next = child = NULL;
        this->val = val;
    }
};*/

Node* flatten(Node* head) {
    if (!head) return head;

    Node* curr = head;
    stack<Node*> st;  // store "next" nodes when diving into child

    while (curr) {
        if (curr->child) {
            // if there is a next, save it for later
            if (curr->next) {
                st.push(curr->next);
            }

            // attach child as next
            curr->next = curr->child;
            curr->child = NULL;
        }

        // if we reach end and stack not empty → pop from stack
        if (!curr->next && !st.empty()) {
            curr->next = st.top();
            st.pop();
        }

        curr = curr->next;
    }

    return head;
}
