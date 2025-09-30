/*struct Node{
	int label;
	struct Node *left,*right;
	Node(int x){
		label = x;
		left = NULL;
		right = NULL;
	}
};*/
void solve(Node* root){
    if (root == NULL) return ;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        auto front = q.front();q.pop();
        cout << front->label << " ";
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }
}
Node* reconstruct(vector <int> traversal){
    int n = traversal.size();
    if (n == 0) return NULL;
    queue<Node*> q;
    int index = 0;
    Node* root = new Node(traversal[0]);
    q.push(root);
    while (!q.empty() && index < n - 1){
        auto size = q.size();
        for (int i = 0; i < size; i++){
            auto front = q.front();q.pop();
            Node* left = NULL;
            Node* right = NULL;
            if (index < n - 1){
                left = new Node(traversal[++index]);
                q.push(left);
            }
            if (index < n - 1){
                right = new Node(traversal[++index]);
                q.push(right);
            }
            
            if (left) front->left = left;
            if (right) front->right = right;
            if (index >= n - 1) return root;
        }
    }
    
    // solve(root);
    
    return root;
}