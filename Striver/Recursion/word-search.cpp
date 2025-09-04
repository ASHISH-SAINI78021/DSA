class Solution {
public:
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};

    bool solve(vector<vector<char>> &board, int row, int col, int idx, string &word, vector<vector<int>> &visited){
        // base case
        if (idx == word.size() - 1) return true;

        visited[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        bool ans = false;
        for (int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && board[nrow][ncol] == word[idx + 1]){
                ans = ans || solve(board, nrow, ncol, idx + 1, word, visited);
            }
        }

        visited[row][col] = 0; // backtrack
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0)); 

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == word[0]){
                    if (solve(board, i, j, 0, word, visited)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
