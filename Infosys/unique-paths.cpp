class Solution {
public:
    // int solve(int m, int n, vector<vector<int>> &dp){
    //     // base case
    //     if (m < 0 || n < 0) return 0;
    //     if (m == 0 && n == 0) return 1;
    //     if (dp[m][n] != -1) return dp[m][n];

    //     // solution for one case
    //     int ans1 = solve(m - 1, n, dp);
    //     int ans2 = solve(m, n - 1, dp);

    //     return dp[m][n] = ans1 + ans2;
    // }
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) return 1;
        if (m == 2 && n == 2) return 2;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[1][1] = 1;

        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (i == 1 && j == 1) continue; // don't overwrite base case
                int ans1 = dp[i - 1][j];
                int ans2 = dp[i][j - 1];

                dp[i][j] = ans1 + ans2;
            }
        }
        return dp[m][n];
    }
};