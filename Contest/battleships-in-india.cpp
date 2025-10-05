#include <vector>

class Solution {
public:
    int countBattleships(std::vector<std::vector<char>>& board) {
        // Handle empty board case
        if (board.empty() || board[0].empty()) {
            return 0;
        }

        int num_rows = board.size();
        int num_cols = board[0].size();
        int count = 0;

        // Iterate through every cell of the board
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                // Skip if it's just water
                if (board[i][j] == '.') {
                    continue;
                }

                // Check if there is a battleship part above the current cell.
                // If there is, we've already counted this ship.
                if (i > 0 && board[i - 1][j] == 'X') {
                    continue;
                }

                // Check if there is a battleship part to the left of the current cell.
                // If there is, we've already counted this ship.
                if (j > 0 && board[i][j - 1] == 'X') {
                    continue;
                }

                // If we reach here, it means the current 'X' is the top-leftmost
                // part of a new battleship, so we increment our count.
                count++;
            }
        }

        return count;
    }
};