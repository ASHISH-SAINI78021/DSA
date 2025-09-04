class Solution {
  public:
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};
    string dir = "DLRU";
    void dfs(vector<vector<int>> &maze, int &n, int row, int col, vector<vector<int>> &visited, string &output, vector<string> &ans){
        // base case
        if (row == n - 1 && col == n - 1){
            ans.push_back(output);
            return ;
        }
        
        
        // solution for one case
        for (int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && visited[nrow][ncol] == 0 && maze[nrow][ncol] == 1){
                output.push_back(dir[i]);
                visited[nrow][ncol] = 1;
                dfs(maze, n, nrow, ncol, visited, output, ans);
                visited[nrow][ncol] = 0;
                output.pop_back();
            }
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        int m = maze[0].size();
        if (maze[0][0] == 0){
            // ans.push_back("-1");
            return ans;
        }
        vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
        int row = 0;
        int col = 0;
        visited[row][col] = 1;
        string output;
        
        dfs(maze, n, row, col, visited, output, ans);
        
        if (ans.empty()){
            // ans.push_back("-1");
            return ans;
        }
        
        return ans;
    }
};