class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V, 1e9);
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()){
            auto top = pq.top(); pq.pop();
            int node = top.second;
            int cost = top.first;
            for (auto it : adj[node]){
                if (cost + it.second < dist[it.first]){
                    dist[it.first] = cost + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        
        for (int i = 0; i < V; i++) if (dist[i] >= 1e9) dist[i] = -1;
        
        return dist;
    }
};