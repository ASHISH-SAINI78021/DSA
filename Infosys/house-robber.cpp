class Solution {
public:
    // int solve(vector<int> &nums, int index, vector<int> &dp){
    //     // base case
    //     if (index >= nums.size()) return 0;
    //     if (dp[index] != -1) return dp[index];

    //     // solution for one case
    //     int include = nums[index] + solve(nums, index + 2, dp);
    //     int exclude = solve(nums, index + 1, dp);

    //     return dp[index] = max(include, exclude);
    // }
    int solve2(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--){
            int include = nums[i] + dp[i + 2];
            int exclude = dp[i + 1];
            dp[i] = max(include, exclude);
        }

        return dp[0];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = solve2(nums);

        return ans;
    }
};