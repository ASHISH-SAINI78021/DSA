class Solution {
public:
    int dfs(int node, int parent, vector<vector<pair<int, int>>> &adj, int &signalSpeed, int dist){
        // base case
        int count = (dist % signalSpeed == 0) ? 1 : 0;

        // solution for one case
        for (auto it : adj[node]){
            if (parent != it.first){
                count += dfs(it.first, node, adj, signalSpeed, dist + it.second);
            }
        }

        return count;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<int> ans(n);
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        for (int i = 0; i < n; i++){
            if (adj[i].size() < 2) continue ;
            long long nodes = 0;
            for (auto it : adj[i]){
                long long branchCount = dfs(it.first, i, adj, signalSpeed, it.second);
                ans[i] += nodes * branchCount;
                nodes += branchCount;
            }
        }

        return ans;
    }
};