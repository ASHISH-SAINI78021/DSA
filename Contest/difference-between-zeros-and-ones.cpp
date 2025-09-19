class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> onesRow(n, 0);
        vector<int> onesCol(m, 0);

        for (int i = 0; i < n; i++){
            int count = 0;
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1) count++;
            }
            onesRow[i] = count;
        }
        int j = 0;
        while (j < m){
            int count = 0;
            int i = 0;
            while (i < n){
                if (grid[i][j] == 1) count++;
                i++;
            }
            onesCol[j] = count;
            j++;
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                grid[i][j] = onesRow[i] + onesCol[j] - (m - onesRow[i]) - (n - onesCol[j]);
            }
        }

        // for (int i = 0; i < n; i++){
        //     cout << onesRow[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < m; i++){
        //     cout << onesCol[i] << " ";
        // }

        return grid;
    }
};