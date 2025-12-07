class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        using T = pair<int, pair<int, int>>;
        int maxTime = 0;
        queue<T> q;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    visited[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }

        int arr[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int time = front.first;
            int row = front.second.first;
            int col = front.second.second;
            maxTime = max(maxTime, time);
            
            for (int i = 0; i < 4; i++){
                int nrow = row + arr[i][0];
                int ncol = col + arr[i][1];

                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({time + 1, {nrow, ncol}});
                    visited[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1) return -1;
            }
        }

        return maxTime;
    }
};