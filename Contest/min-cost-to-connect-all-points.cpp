class Solution {
public:
    int manhattan_distance(vector<int> &arr1, vector<int> &arr2){
        return abs(arr1[0] - arr2[0]) + abs(arr1[1] - arr2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> dist(n, 1e9);
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        int mst = 0;

        while (!pq.empty()){
            auto top = pq.top(); pq.pop();
            int cost = top.first;
            int u = top.second;
            if (visited[u] || dist[u] < cost) continue ;
            mst += cost;

            for (int i = 0; i < n; i++){
                if (!visited[i]){
                    int newCost = manhattan_distance(points[u], points[i]);
                    if (newCost < dist[i]){
                        dist[i] = newCost;
                        pq.push({newCost, i});
                    }
                }
            }
        }

        return mst;
    }
};