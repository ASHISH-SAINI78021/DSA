// struct Node{
// 	int data;
// 	struct Node *left,*right;
// 	Node(int x){
// 		data = x;
// 		left = NULL;
// 		right = NULL;
// 	}
// };
Node* solve(Node* root, int a, int b, int c){
    // base case
    if (root == NULL) return root;
    if (root->data == a || root->data == b || root->data == c) return root;
    
    // solution for one case
    auto ansleft = solve(root->left, a, b, c);
    auto ansright = solve(root->right, a, b, c);
    
    if (ansleft == NULL && ansright != NULL) return ansright;
    else if (ansleft != NULL && ansright == NULL) return ansleft;
    else if (ansleft == NULL && ansright == NULL) return NULL;
    
    return root;
}
int tripletLCA(Node* root,  int a, int b, int c){
   if (root == NULL) return 0;
   Node* ans = solve(root, a, b, c);
   
   return ans->data;
}