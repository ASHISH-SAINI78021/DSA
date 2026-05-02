class Solution {
public:
    // int solve(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp){
    //     // base case
    //     if (i == triangle.size() - 1) return triangle[i][j];
    //     if (i >= triangle.size()) return 1e9;
    //     if (dp[i][j] != -1) return dp[i][j];

    //     // solution for one case
    //     int ans1 = solve(triangle, i + 1, j, dp);
    //     int ans2 = solve(triangle, i + 1, j + 1, dp);
    //     return dp[i][j] = triangle[i][j] + min(ans1, ans2);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        for (int j = 0; j < n; j++) dp[n - 1][j] = triangle[n - 1][j];

        for (int i = n - 1; i >= 0; i--){
            for (int j = 0; j <= i; j++){
                if (i == n - 1) continue ;
                int ans1 = dp[i + 1][j];
                int ans2 = dp[i + 1][j + 1];

                dp[i][j] = triangle[i][j] + min(ans1, ans2);
            }
        }

        return dp[0][0];
    }
};