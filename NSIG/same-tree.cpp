class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q){
        if (p == NULL && q == NULL) return true;
        else if (p != NULL && q == NULL) return false;
        else if (q != NULL && p == NULL) return false;
        else if (p->val != q->val) return false;

        bool ansleft = solve(p->left, q->left);
        bool ansright = solve(p->right, q->right);

        return ansleft && ansright;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};

// T.C -> O(2*n)
// S.C -> O(2*n)