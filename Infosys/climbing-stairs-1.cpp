class Solution {
public:
    // int solve(int n, vector<int> &dp){
    //     // base case
    //     if (n == 0) return 1;
    //     if (n < 0) return 0;
    //     if (dp[n] != -1) return dp[n];

    //     // solution for one case
    //     int ans1 = solve(n - 1, dp);
    //     int ans2 = solve(n - 2, dp);

    //     return dp[n] = ans1 + ans2;
    // }
    int solve2(int n){
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            int ans1 = dp[i - 1];
            int ans2 = 0;
            if (i - 2 >= 0) ans2 = dp[i - 2];

            dp[i] = ans1 + ans2;
        }

        return dp[n];
    }
    int climbStairs(int n) {
        int ans = solve2(n);

        return ans;
    }
};