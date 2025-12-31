class Solution {
public:
    int d = 0;
    int solve(TreeNode* root){
        if (root == NULL) return 0;
        int ansleft = solve(root->left);
        int ansright = solve(root->right);
        d = max(d, ansleft + ansright);
        return max(ansleft, ansright) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = solve(root);

        return d;
    }
};


// T.C -> O(n)
// S.C -> O(n)