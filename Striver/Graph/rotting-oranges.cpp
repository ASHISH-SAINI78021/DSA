class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Directions: up, right, down, left
        int arr[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        int minTime = 0;

        // Push all initially rotten oranges
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int time = front.first;
            int row = front.second.first;
            int col = front.second.second;

            minTime = max(minTime, time);

            for (int i = 0; i < 4; i++){
                int nrow = row + arr[i][0];
                int ncol = col + arr[i][1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0) {
                    
                    q.push({time + 1, {nrow, ncol}});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        // Check if any fresh orange is unvisited
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1 && visited[i][j] == 0) return -1;
            }
        }

        return minTime;
    }
};