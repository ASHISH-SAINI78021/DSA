class Solution {
public:
    void solve(TreeNode* root, int &sum){
        // base case
        if (root == NULL) return ;

        // solution for one case
        solve(root->right, sum);
        sum = sum + root->val;
        root->val = sum;
        solve(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if (root == NULL) return root;
        int sum = 0;
        solve(root, sum);

        return root;
    }
};