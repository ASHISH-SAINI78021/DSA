class Solution {
public:
    TreeNode* solve(vector<int> &nums, int start, int end){
        // base case
        if (start > end) return NULL;

        // solution for one case
        int index = 0;
        int maxValue = INT_MIN;
        for (int i = start; i <= end; i++){
            if (nums[i] > maxValue){
                maxValue = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(maxValue);
        root->left = solve(nums, start, index - 1);
        root->right = solve(nums, index + 1, end);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        TreeNode* root = solve(nums, start, end);

        return root;
    }
};