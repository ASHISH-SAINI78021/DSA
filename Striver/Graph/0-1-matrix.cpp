class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans = mat;
        vector<vector<int>> visited(n + 1, vector<int> (m + 1, 0));
        queue<pair<pair<int, int>, int>> q;
        
        for (int i = 0; i < n; i++){
            
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.empty()){
            auto front = q.front();
            int row = front.first.first;
            int col = front.first.second;
            int cost = front.second;
            q.pop();

            if (mat[row][col] == 0){
                ans[row][col] = 0;
            }
            else {
                ans[row][col] = cost;
            }


            int drow[] = {-1 , 0 , 1 , 0};
            int dcol[] = {0 , 1 , 0 , -1};

            for (int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && mat[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, cost + 1});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        return ans;
    }
};