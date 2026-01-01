class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q){
        if (p == NULL && q == NULL) return true;
        else if (p != NULL && q == NULL) return false;
        else if (p == NULL && q != NULL) return false;
        else if (p->val != q->val) return false;

        bool ansleft = solve(p->left, q->right);
        bool ansright = solve(p->right, q->left);

        return ansleft && ansright;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        bool ans = solve(root->left, root->right);

        return ans;
    }
};

// T.C -> O(n)
// S.C -> O(n)