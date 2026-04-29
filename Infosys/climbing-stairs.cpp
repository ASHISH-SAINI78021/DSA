class Solution {
public:
    int solve(int n, vector<int> &dp){
        // base case
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];

        // solution for one case
        int ans1 = solve(n - 1, dp);
        int ans2 = solve(n - 2, dp);

        return dp[n] = ans1 + ans2;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        int ans = solve(n, dp);

        return ans;
    }
};