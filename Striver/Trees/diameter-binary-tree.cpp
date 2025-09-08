class Solution {
public:
    int d = 0;
    int calculateHeight(TreeNode* root){
        // base case
        if (root == NULL) return 0;

        // solution for one case
        int ansleft = calculateHeight(root->left);
        int ansright = calculateHeight(root->right);
        d = max(d, ansleft + ansright);

        return max(ansleft, ansright) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = calculateHeight(root);

        return d;
    }
};