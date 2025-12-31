class Solution {
public:
    int solve(TreeNode* root){
        if (root == NULL) return 0;
        int ansleft = solve(root->left);
        int ansright = solve(root->right);

        if (abs(ansleft - ansright) > 1) return 1e9;

        return max(ansleft, ansright) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int ans = solve(root);
        if (ans >= 1e9) return false;

        return true;
    }
};