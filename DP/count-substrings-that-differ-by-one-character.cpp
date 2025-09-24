class Solution {
public:
    int solve(string &s, string &t, int n, int m, int k, vector<vector<vector<int>>> &dp){
        // base case
        if (n < 0 || m < 0) return 0;
        if (dp[n][m][k] != -1) return dp[n][m][k];

        // solution for one case
        if (s[n] == t[m]){
            if (k == 0) return dp[n][m][k] = 1 + solve(s, t, n - 1, m - 1, 0, dp);
            return dp[n][m][k] = solve(s, t, n - 1, m - 1, k, dp);
        }
        else {
            if (k == 0) return dp[n][m][k] = 0;
            return dp[n][m][k] = 1 + solve(s, t, n - 1, m - 1, 0, dp);
        }
    }
    int countSubstrings(string s, string t) {
        int n = s.length();
        int m = t.length();
        int ans = 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1)));

        for (int i = 0; i < n; i++){
            for (int j = 0;  j < m; j++){
                ans += solve(s, t, i, j, 1, dp);
            }
        }

        return ans;
    }
};