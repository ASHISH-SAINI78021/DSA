class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == NULL) return root;
        if (root == p) return p;
        if (root == q) return q;
        TreeNode* ansleft = solve(root->left, p, q);
        TreeNode* ansright = solve(root->right, p, q);

        if (ansleft != NULL && ansright != NULL) return root;
        else if (ansleft != NULL && ansright == NULL) return ansleft;
        else if (ansleft == NULL && ansright != NULL) return ansright;
        else return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        TreeNode* ans = solve(root, p, q);

        return ans;
    }
};


    //         3 -

    //     5         1

    // 6      2     0     8

    //     7      4