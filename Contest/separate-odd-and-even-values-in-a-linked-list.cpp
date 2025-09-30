/*struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *n) : val(x), next(n) {}
  };
  */
class Solution{
	public:
	Node* rearrange(Node* head)
	{
		if (head == NULL) return NULL;
		Node* odd = new Node(0);
		Node* temp = odd;
		Node* even = new Node(0);
		Node* temp2 = even;
		
	    Node* curr = head;
	    while (curr != NULL){
	        if (curr->val & 1){
	            temp->next = curr;
	            temp = temp->next;
	        }
	        else {
	            temp2->next = curr;
	            temp2 = temp2->next;
	        }
	        curr = curr->next;
	    }
	    temp2->next = NULL;
	    temp->next = NULL;
	    
	    temp2->next = odd->next;
	    return even->next;
	}
};