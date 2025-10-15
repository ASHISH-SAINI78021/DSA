class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char col = coordinates[0];
        char row = coordinates[1];

        int isEvenRow = (row - '0') % 2 == 0;
        int isOddCol = (col - 'a') % 2 != 0;

        return isEvenRow != isOddCol;
    }
}; 