class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int drow[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
        int dcol[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};
        int n = grid.size(); int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        using T = pair<int, pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({1, {0, 0}});
        dist[0][0] = 1;
        while (!pq.empty()){
            auto top = pq.top(); pq.pop();
            int cost = top.first;
            int row = top.second.first;
            int col = top.second.second;

            if (grid[row][col] == 1) continue ;

            for (int i = 0; i < 8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0){
                    if (cost + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = 1 + cost;
                        pq.push({1 + cost, {nrow, ncol}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1] == 1e9 ? -1 : dist[n - 1][m - 1];
    }
};