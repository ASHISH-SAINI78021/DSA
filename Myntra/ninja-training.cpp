#include <bits/stdc++.h>
int solve(vector<vector<int>> &points, int prev, int index, vector<vector<int>> &dp){
    // base case
    if (index >= points.size()) return 0;
    if (dp[index][prev] != -1) return dp[index][prev];

    int ans = INT_MIN;
    for (int i = 0; i < 3; i++){
        int result = INT_MIN;
        if (i != prev){
            result = points[index][i] + solve(points, i, index + 1, dp);
        }
        ans = max(result, ans);
    }

    return dp[index][prev] = ans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int maxi = 0;
    for (int i = 0; i < 3; i++){
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));
        maxi = max(maxi, points[0][i] + solve(points, i, 1, dp));
    }

    return maxi;
}