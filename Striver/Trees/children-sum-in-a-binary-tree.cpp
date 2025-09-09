class Solution {
  public:
    int solve(Node* root, int &result){
        // base case
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->data;
        
        // solution in one case
        int ansleft = solve(root->left, result);
        int ansright = solve(root->right, result);
        
        if (ansleft + ansright != root->data){
            result = false;
        }
        
        return ansleft + ansright;
    }
    int isSumProperty(Node *root) {
        if (root == NULL) return 1;
        int result = 1;
        solve(root, result);
        
        return result;
    }
};