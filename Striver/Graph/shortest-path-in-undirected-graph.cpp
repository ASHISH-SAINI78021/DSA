class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({0, src});
        dist[src] = 0;
        while (!q.empty()){
            auto front = q.front(); q.pop();
            int node = front.second;
            int cost = front.first;
            for (auto it : adj[node]){
                int v = it;
                if (cost + 1 < dist[v]){
                    dist[v] = cost + 1;
                    q.push({dist[v], it});
                }
            }
        }
        
        for (int i = 0; i < n; i++){
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
    }
};