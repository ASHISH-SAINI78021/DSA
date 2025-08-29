class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, -1);
        vector<int> col(m, -1);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == 0){
                    row[i] = i;
                    col[j] = j;
                }
            }
        }

        // for rows
        for (int i = 0; i < n; i++){
            if (row[i] != -1){
                for (int j = 0; j < m; j++){
                    matrix[row[i]][j] = 0;
                }
            }
        }

        // for columns
        for (int i = 0; i < m; i++){
            if (col[i] != -1){
                for (int j = 0; j < n; j++){
                    matrix[j][col[i]] = 0;
                }
            }
        }
    }
};