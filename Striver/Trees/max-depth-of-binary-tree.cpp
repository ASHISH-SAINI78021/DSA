class Solution {
public:
    int calculateHeight(TreeNode* root){
        // base case
        if (root == NULL) return 0;

        // solution for one case
        int ansleft = calculateHeight(root->left);
        int ansright = calculateHeight(root->right);

        return max(ansleft, ansright) + 1;
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = calculateHeight(root);

        return ans;
    }
};