class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> arr(m, vector<int>(n, 0));
        for (int k = 0; k < indices.size(); k++){
            int row = indices[k][0];
            int col = indices[k][1];
            for (int j = 0; j < n; j++){
                arr[row][j]++;
            }
            for (int i = 0; i < m; i++){
                arr[i][col]++;
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) if (arr[i][j] & 1) count++;
        }

        return count;
    }
};