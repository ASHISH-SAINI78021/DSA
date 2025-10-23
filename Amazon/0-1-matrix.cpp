class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int drow[] = {-1 , 0 , 1 , 0}; int dcol[] = {0 , 1 , 0 , -1};
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans = mat;
        vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
        queue<pair<int, pair<int,int>>> q;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 0){
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int cost = front.first;
            int row = front.second.first;
            int col = front.second.second;

            if (mat[row][col] == 0){
                ans[row][col] = 0;
            }
            else {
                ans[row][col] = cost;
            }

            for (int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && mat[nrow][ncol] == 1){
                    q.push({cost + 1, {nrow, ncol}});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        return ans;
    }
};