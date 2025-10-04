class Solution {
public:
    const int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();

            for (auto &[neighbor, wt] : adj[node]) {
                if (time + wt < dist[neighbor]) {
                    dist[neighbor] = time + wt;
                    pq.push({dist[neighbor], neighbor});
                    ways[neighbor] = ways[node];
                } else if (time + wt == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
