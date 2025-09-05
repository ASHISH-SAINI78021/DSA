#include <bits/stdc++.h> 
long long int solve(vector<int> &arr, int index, int n, vector<long long int> &dp){
    // base case
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];

    // solution for one case
    long long int include = arr[index] + solve(arr, index + 2, n, dp);
    long long int exclude = solve(arr, index + 1, n, dp);

    return dp[index] = max(include, exclude);
}
long long int houseRobber(vector<int>& arr)
{
    long long int ans1 = 0;
    long long int ans2 = 0;
    int index = 0;
    int n = arr.size();
    if (n == 1) return arr[0];
    vector<long long int> dp1(n + 1, -1);
    vector<long long int> dp2(n + 1, -1);
    ans1 = solve(arr, index, n - 1, dp1);
    ans2 = solve(arr, index + 1, n, dp2);

    return max(ans1, ans2);
}