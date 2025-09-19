class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> solve(int n){
        // base case
        if (memo.count(n)) return memo[n];
        vector<TreeNode*> ans;
        if (n % 2 == 0) return {};
        if (n == 1){
            TreeNode* node = new TreeNode(0);
            ans.push_back(node);

            return ans;
        }

        // solution for one case
        for (int i = 1; i < n; i += 2){
            vector<TreeNode*> left = solve(i);
            vector<TreeNode*> right = solve(n - i - 1);
            for (auto l : left){
                for (auto r: right){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return memo[n] = ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if (n == 0) return ans;
        if (!(n & 1)) return ans;

        ans = solve(n);

        return ans;
    }
};