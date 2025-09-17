class Solution {
public:
    int ans = 0;
    pair<int, int> solve(TreeNode* root){
        // base case
        if (root == NULL) return {0, 0};
    
        // solution for one case
        auto ansleft = solve(root->left);
        auto ansright = solve(root->right);

        int sum = ansleft.first + ansright.first + root->val;
        int count = ansright.second + ansleft.second + 1;
        if (sum/count == root->val) ans++;

        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        if (root == NULL) return 0;
        solve(root);

        return ans;
    }
};