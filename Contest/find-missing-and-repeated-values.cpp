class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        vector<int> visited(n*n+ 1, 0);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                arr.push_back(grid[i][j]);
            }
        }

        int twice = 0;
        int missing = 0;
        for (int i = 0; i < arr.size(); i++){
            int index = arr[i];
            if (visited[index] == 1) twice = index;
            else {
                visited[index] = 1;
            }
        }
        for (int i = 1; i <= n*n; i++){
            if (visited[i] == 0){
                missing = i;
                break;
            }
        }

        return {twice, missing};
    }
};