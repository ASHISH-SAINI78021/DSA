class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> maxRow(n, 0);
        vector<int> maxCol(m, 0);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                maxRow[i] = max(maxRow[i], grid[i][j]);
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                maxCol[i] = max(maxCol[i], grid[j][i]);
            }
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                sum += abs(min(maxRow[i], maxCol[j]) - grid[i][j]);
            }
        }

        return sum;
    }
};