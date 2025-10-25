class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid, long long &value){
        // base case
        value += grid[row][col];
        visited[row][col] = 1;

        // solution for one case
        int drow[] = {-1 , 0 , 1 , 0}; int dcol[] = {0 , 1 , 0 , -1};
        int n = grid.size(); int m = grid[0].size();
        for (int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] != 0){
                dfs(nrow, ncol, visited, grid, value);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        long long count = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (visited[i][j] == 0 && grid[i][j] != 0){
                    long long value = 0;
                    dfs(i, j, visited, grid, value);
                    if (value % k == 0) count++;
                }
            }
        }

        return count;
    }
};