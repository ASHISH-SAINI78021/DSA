class Solution {
public:
    int solve(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp){
        // base case
        if (i < 0 || j < 0) return 0;
        if (matrix[i][j] == 0) return 0;
        if (j == 0 || i == 0) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        // solution for one case
        int up = solve(matrix, i - 1, j, dp);
        int left = solve(matrix, i, j - 1, dp);
        int diag = solve(matrix, i - 1, j - 1, dp);

        return dp[i][j] = 1 + min({up, left, diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                count += solve(matrix, i, j, dp);
            }
        }

        return count;
    }
};