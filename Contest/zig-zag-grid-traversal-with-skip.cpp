class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> temp;
        int n = grid.size();
        int m = grid[0].size();
        bool leftToRight = true;

        for (int i = 0; i < n; i++){
            if (leftToRight){
                for (int j = 0; j < m; j++){
                    temp.push_back(grid[i][j]);
                }
            }
            else {
                for (int j = m - 1; j >= 0; j--){
                    temp.push_back(grid[i][j]);
                }
            }
            leftToRight = !leftToRight;
        }

        vector<int> ans;
        for (int i = 0; i < n*m; i += 2){
            ans.push_back(temp[i]);
        }

        return ans;
    }
};