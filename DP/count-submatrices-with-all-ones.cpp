class Solution {
public:
    // compute consecutive 1s ending at column j in row (i)
    int getWidth(const vector<int> &row, int j){
        int count = 0;
        for (int x = j; x >= 0; --x){
            if (row[x] == 1) count++;
            else break;
        }
        return count;
    }

    // compute number of submatrices that end at (i,j)
    int solve(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &width) {
        if (i < 0 || j < 0) return 0;
        if (mat[i][j] == 0) return dp[i][j] = 0;
        if (dp[i][j] != -1) return dp[i][j];

        // use precomputed width to accumulate contribution by going up
        int minWidth = INT_MAX;
        int ans = 0;
        for (int k = i; k >= 0; --k) {
            if (width[k][j] == 0) break;                // no more rectangles if a 0 encountered
            minWidth = min(minWidth, width[k][j]);
            ans += minWidth;
        }
        return dp[i][j] = ans;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // precompute width[i][j]
        vector<vector<int>> width(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) width[i][j] = (j == 0 ? 1 : width[i][j-1] + 1);
                else width[i][j] = 0;
            }
        }

        vector<vector<int>> dp(n, vector<int>(m, -1));
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += solve(mat, i, j, dp, width);
            }
        }
        return (int)ans;
    }
};