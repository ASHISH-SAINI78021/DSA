class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, int &count){
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
            
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || grid[nrow][ncol] == 0) count++;
            else if (visited[nrow][ncol] == 0){
                dfs(nrow, ncol, grid, visited, count);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        int count = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (visited[i][j] == 0 && grid[i][j] == 1){
                    dfs(i, j, grid, visited, count);
                    return count;
                }
            }
        }

        return count;
    }
};