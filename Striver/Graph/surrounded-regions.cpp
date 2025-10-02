class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &board){
        // base case
        visited[row][col] = 1;

        // solution for one case
        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , 1 , 0 , -1};
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, visited, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < m; i++){
            // first row
            if (board[0][i] == 'O' && visited[0][i] == 0) dfs(0, i, visited, board);

            // last row
            if (board[n - 1][i] == 'O' && visited[n - 1][i] == 0) dfs(n - 1, i, visited, board);
        }
        for (int i = 0; i < n; i++){
            // first col
            if (board[i][0] == 'O' && visited[i][0] == 0) dfs(i, 0, visited, board);

            // last col
            if (board[i][m - 1] == 'O' && visited[i][m - 1] == 0) dfs(i, m - 1, visited, board);
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (visited[i][j] == 0 && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};