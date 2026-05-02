class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &arr, vector<vector<int>> &dp){
        // base case
        if (m < 0 || n < 0 || arr[m][n] == 1) return 0;
        if (m == 0 && n == 0) return 1;
        if (dp[m][n] != -1) return dp[m][n];

        // solution for one case
        int ans1 = solve(m - 1, n, arr, dp);
        int ans2 = solve(m, n - 1, arr, dp);

        return dp[m][n] = ans1 + ans2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        if (m == 1 && n == 1 && arr[0][0] == 1) return 0;
        if (arr[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int ans = solve(m - 1, n - 1, arr, dp);

        return ans;
    }
};