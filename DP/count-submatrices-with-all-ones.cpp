class Solution {
public:
    int solve(vector<vector<int>> &mat, int i, int j){
        // base case
        if (i < 0 || j < 0) return 0;
        if (mat[i][j] == 0) return 0;

        // solution for one case
        int ans1 = solve(mat, i - 1, j);
        int ans2 = solve(mat, i, j - 1);
        int ans3 = solve(mat, i - 1, j - 1);

        return 
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 1){
                    ans += solve(mat, i, j);
                }
            }
        }

        return ans;
    }
};