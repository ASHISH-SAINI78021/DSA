class Solution {
public:
    int solve(vector<int> &nums, int index, int prev, vector<vector<int>> &dp){
        // base case
        if (index >= nums.size()) return 0;
        if (dp[index][prev + 1] != -1) return dp[index][prev + 1];

        // solution for one case
        int include = 0;
        if (prev == -1 || nums[prev] < nums[index]){
            include = 1 + solve(nums, index + 1, index, dp);
        }
        int exclude = solve(nums, index + 1, prev, dp);

        return dp[index][prev + 1] = max(include, exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int prev = -1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        int ans = solve(nums, index, prev, dp);

        return ans;
    }
};