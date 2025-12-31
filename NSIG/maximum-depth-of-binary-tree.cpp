class Solution {
public:
    int solve(TreeNode* root){
        if (root == NULL) return 0;
        int ansleft = solve(root->left);
        int ansright = solve(root->right);

        return max(ansleft, ansright) + 1;
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = solve(root);

        return ans;
    }
};

//    3
// 9       20
//     15      7


// T.C -> O(n)
// S.C -> O(n)