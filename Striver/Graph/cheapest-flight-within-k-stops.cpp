class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, 1e9);
        for (int i = 0; i < arr.size(); i++){
            int u = arr[i][0];
            int v = arr[i][1];
            int wt = arr[i][2];
            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q; // {stops, {u, wt}};
        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int stops = front.first;
            int node = front.second.first;
            int cost = front.second.second;

            if (stops > k) continue ;

            for (auto it : adj[node]){
                if (cost + it.second < dist[it.first] && stops <= k){
                    dist[it.first] = cost + it.second;
                    q.push({stops + 1, {it.first, cost + it.second}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};