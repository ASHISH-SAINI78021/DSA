class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>> &visited, vector<vector<char>> &board){
        visited[sr][sc] = 1;
        int arr[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < 4; i++){
            int nrow = sr + arr[i][0];
            int ncol = sc + arr[i][1];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, visited, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++){
            char src1 = board[i][0];
            if (src1 == 'O'){
                dfs(i, 0, visited, board);
            }
            
            char src2 = board[i][m - 1];
            if (src2 == 'O'){
                dfs(i, m - 1, visited, board);
            }
        }

        for (int j = 0; j < m; j++){
            char src1 = board[0][j];
            if (src1 == 'O'){
                dfs(0, j, visited, board);
            }

            char src2 = board[n - 1][j];
            if (src2 == 'O'){
                dfs(n - 1, j, visited, board);
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (visited[i][j] == 0 && board[i][j] == 'O') board[i][j] = 'X'; 
            }
        }
    }
};