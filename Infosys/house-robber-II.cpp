class Solution {
public:
    int solve(vector<int> &nums, int index, int n, vector<int> &dp){
        // base case
        if (index > n) return 0;
        if (dp[index] != -1) return dp[index];

        // solution for one case
        int ans1 = nums[index] + solve(nums, index + 2, n, dp);
        int ans2 = solve(nums, index + 1, n, dp);

        return dp[index] = max(ans1, ans2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        int ans1 = solve(nums, 0, n - 2, dp1);
        int ans2 = solve(nums, 1, n - 1, dp2);

        return max(ans1, ans2);
    }
};