class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        // base case
        if (root == NULL) return root;
        if (p == root || q == root) return root;


        // solution for one case
        auto ansleft = solve(root->left, p, q);
        auto ansright = solve(root->right, p, q);

        if (ansleft != NULL && ansright == NULL) return ansleft;
        else if (ansleft == NULL && ansright != NULL) return ansright;
        else if (ansleft == NULL && ansright == NULL) return NULL;

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        return solve(root, p, q);
    }
};