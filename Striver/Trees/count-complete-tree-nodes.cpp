class Solution {
public:
    int count = 0;
    void solve(TreeNode* root){
        // base case
        if (root == NULL) return ;

        // solution for one case
        count++;
        solve(root->left);
        solve(root->right);
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        solve(root);

        return count;
    }
};