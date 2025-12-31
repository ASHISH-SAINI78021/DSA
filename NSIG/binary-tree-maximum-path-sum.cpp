class Solution {
public:
    int maxSum = INT_MIN;
    int solve(TreeNode* root){
        if (root == NULL) return 0;
        int ansleft = max(0, solve(root->left));
        int ansright = max(0, solve(root->right));

        maxSum = max(maxSum, ansleft + ansright + root->val);

        return root->val + max(ansleft, ansright);
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = solve(root);

        return maxSum;
    }
};


// T.C -> O(n)
// S.C -> O(n)