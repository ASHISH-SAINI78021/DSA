class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q){
        // base case
        if (p != NULL && q == NULL) return false;
        else if (p == NULL && q != NULL) return false;
        else if (p == NULL && q == NULL) return true;
        else if (p->val != q->val) return false;

        // solution for one case
        bool ansleft = solve(p->left, q->left);
        bool ansright = solve(p->right, q->right);

        return ansleft && ansright;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = solve(p, q);
        
        return ans;
    }
};