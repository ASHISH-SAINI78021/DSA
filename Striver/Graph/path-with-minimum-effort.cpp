class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n + 1, vector<int>(m + 1, 1e9));
        pq.push({0, {0,0}});
        dist[0][0] = 0;
        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , 1 , 0 , -1};

        while (!pq.empty()){
            auto front = pq.top();pq.pop();
            int effort = front.first;
            int row = front.second.first;
            int col = front.second.second;

            if (row == n - 1 && col == m - 1) return effort;
            for (int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int newEffort = max(effort, abs(arr[nrow][ncol] - arr[row][col]));
                    if (newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }


        return 0;
    }
};