class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid){
        // base case
        visited[row][col] = 1;

        // solution for one case
        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , 1 , 0 , -1};
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 1 && nrow < n - 1 && ncol >= 1 && ncol < m - 1 && grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0) dfs(nrow, ncol, visited, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n + 1, vector<int> (m + 1, 0));
        int count = 0;

        for (int i = 0; i < m; i++){
            // first row 
            if (grid[0][i] == 1 && visited[0][i] == 0) dfs(0, i, visited, grid);
            // last row
            if (grid[n - 1][i] == 1 && visited[n - 1][i] == 0) dfs(n - 1, i, visited, grid);
        }

        for (int j = 0; j < n; j++){
            // first column
            if (grid[j][0] == 1 && visited[j][0] == 0) dfs(j, 0, visited, grid);
            // last column
            if (grid[j][m - 1] == 1 && visited[j][m - 1] == 0) dfs(j, m - 1, visited, grid);
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (visited[i][j] == 0 && grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};