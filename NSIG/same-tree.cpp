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

// T.C -> min(no: of nodes in p, no: of nodes in q)
// S.C -> O(h)
// Where h -> n when given tree is skew tre
// where h -> n when given tree is balanced