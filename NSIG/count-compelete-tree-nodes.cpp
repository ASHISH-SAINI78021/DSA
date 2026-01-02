class Solution {
public:
    int count = 0;
    void solve(TreeNode* root){
        if (root == NULL) return ;
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