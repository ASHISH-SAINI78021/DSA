class Solution {
public:
    int solve(vector<int> &nums, int index, vector<int> &dp){
        // base case
        if (index >= nums.size() - 1) return 0;
        if (dp[index] != -1) return dp[index];

        // solution for one case
        int ans = INT_MAX;
        int jumps = nums[index];
        for (int i = 1; i <= jumps; i++){
            int result = solve(nums, index + i, dp);
            if (result != INT_MAX){
                ans = min(ans, result + 1);
            }
        }

        return dp[index] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return 0;
        int index = 0;
        vector<int> dp(n, -1);

        return solve(nums, index, dp);
    }
};