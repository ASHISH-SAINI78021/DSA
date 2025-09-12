#include <bits/stdc++.h> 
const int mod = 1e9 + 7;
int solve(vector<vector<int>> &arr, int row, int col, int k, vector<vector<vector<int>>> &dp){
    // base case
    int n = arr.size();
    int m = arr[0].size();
    if (row < 0 || row >= n || col < 0 || col >= m) return 0; 
    if (arr[row][col] == -1) return 0;
    if (k == 1) return 1;
    if (dp[row][col][k] != -1) return dp[row][col][k];
    
    // solution for one case
    long long ans = 0;
    ans += solve(arr, row, col, k - 1, dp) % mod;
    ans += solve(arr, row - 1, col, k - 1, dp) % mod;
    ans += solve(arr, row, col - 1, k - 1, dp) % mod;
    ans += solve(arr, row + 1, col, k - 1, dp) % mod;
    ans += solve(arr, row, col + 1, k - 1, dp) % mod;

    return dp[row][col][k] = ans % mod;
}
int generateNumbers(int n)
{
    vector<vector<int>> arr = {
        {1,2,3},{4,5,6},{7,8,9},{-1,0,-1}
    };
    int count = 0;
    vector<vector<vector<int>>> dp(5, vector<vector<int>> (4, vector<int>(5005, -1)));

    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[0].size(); j++){
            count = (count % mod + solve(arr, i, j, n, dp) % mod) % mod;
        }
    }

    return count;
}