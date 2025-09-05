bool isSafe(int matrix[9][9], int row, int col, int num){
    // checking row
    for (int k = 0; k < 9; k++){
        if (matrix[row][k] == num) return false;
    }

    // checking column
    for (int k = 0; k < 9; k++){
        if (matrix[k][col] == num) return false;
    }

    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (matrix[startRow + i][startCol + i] == num) return false;
        }
    }
    
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (matrix[i][j] == 0){
                for (int k = 1; k <= 9; k++){
                    if (isSafe(matrix, i, j, k)){
                        matrix[i][j] = k;
                        if (isItSudoku(matrix)) return true;
                        matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }

    return true;
}
