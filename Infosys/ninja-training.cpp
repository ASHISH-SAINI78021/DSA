int solve(vector<vector<int>> &points, int index, int prev, vector<vector<int>> &dp){
    // base case
    if (index >= points.size()) return 0;
    if (dp[index][prev] != -1) return dp[index][prev];

    // solution for one case
    int ans = 0;
    for (int i = 0; i < 3; i++){
        if (prev != i){
            int result = points[index][i] + solve(points, index + 1, i, dp);
            ans = max(ans, result);
        }
    }

    return dp[index][prev] = ans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int index = 0;
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int prev = 0; prev < 3; prev++){
        ans = max(ans, points[0][prev] + solve(points, index + 1, prev, dp));
    }

    return ans;
}