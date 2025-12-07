class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        using T = pair<int, pair<int, int>>;
        queue<T> q;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 0){
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }
        int arr[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        while (!q.empty()){
            auto front = q.front(); q.pop();
            int cost = front.first;
            int row = front.second.first;
            int col = front.second.second;

            for (int i = 0; i < 4; i++){
                int nrow = row + arr[i][0];
                int ncol = col + arr[i][1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1 && visited[nrow][ncol] == 0){
                    if (cost + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = 1 + cost;
                        q.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }

        return dist;
    }
};