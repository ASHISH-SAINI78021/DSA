class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        // base case
        if (root == NULL) return ;

        // solution for one case
        solve(root->left, ans);
        solve(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);

        return ans;
    }
};