class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp){
        // base case
        if (m < 0 || n < 0) return 0;
        if (m == 0 && n == 0) return 1;
        if (dp[m][n] != -1) return dp[m][n];

        // solution for one case
        int ans1 = solve(m - 1, n, dp);
        int ans2 = solve(m, n - 1, dp);

        return dp[m][n] = ans1 + ans2;
    }
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) return 1;
        if (m == 2 && n == 2) return 2;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = solve(m - 1, n - 1, dp);
        return ans;
    }
};