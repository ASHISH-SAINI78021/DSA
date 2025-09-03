class Solution {
public:
    bool isSafe(vector<string> &board, int i , int j){
        int row = i;
        int col = j;
        int n = board.size();

        // checking current row
        for (int y = 0; y < j; y++) {
            if (board[row][y] == 'Q') return false;
        }

        // checking upper diagonal
        int r = i, c = j;
        while (r >= 0 && c >= 0){
            if (board[r][c] == 'Q') return false;
            r--; c--;
        }

        // checking lower diagonal
        r = i; c = j;
        while (r < n && c >= 0){
            if (board[r][c] == 'Q') return false;
            r++; c--;
        }

        return true;
    }

    void solve(int n, vector<string> &board, int col, vector<vector<string>> &ans){
        // base case
        if (col >= n){
            ans.push_back(board);
            return ;
        }

        // try placing queen in every row of this column
        for (int i = 0; i < n; i++){
            if (isSafe(board, i, col)){
                board[i][col] = 'Q';
                solve(n, board, col + 1, ans);
                board[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(n, board, 0, ans);
        return ans;
    }
};