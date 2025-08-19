#include <bits/stdc++.h> 
using namespace std;
int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
    // base case
    if (i == j) return arr[i];
    if (i + 1 == j) return max(arr[i], arr[j]);
    if (dp[i][j] != -1) return dp[i][j];

    // solution for one case
    int pickLeft = arr[i] + min(solve(arr, i + 2, j, dp), solve(arr, i + 1, j - 1, dp));
    int pickRight = arr[j] + min(solve(arr, i, j - 2, dp), solve(arr, i + 1, j - 1, dp));

    return dp[i][j] = max(pickLeft, pickRight);
}
int optimalStrategyOfGame(vector<int> coins, int n)
{
    int i = 0;
    int j = n - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(coins, i, j, dp);
}
