class Solution {
public:
    int solve(vector<int> &nums, int index, vector<int> &dp){
        // base case
        if (index >= nums.size()) return 0;
        if (dp[index] != -1) return dp[index];

        // solution for one case
        int ans1 = nums[index] + solve(nums, index + 2, dp);
        int ans2 = solve(nums, index + 1, dp);

        return dp[index] = max(ans1, ans2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int index = 0;
        int ans = solve(nums, index, dp);

        return ans;
    }
};