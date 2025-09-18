class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, int parent) {
        visited[node] = 1;
        
        for (auto it : adj[node]) {
            if (visited[it] == 0) {
                if (dfs(it, adj, visited, node)) {
                    return true;
                }
            }
            else if (parent != it) {
                return true; // cycle detected
            }
        }
        
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> visited(V, 0);
        vector<vector<int>> adj(V);

        // build adjacency list
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // check each component
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, -1)) {
                    return true;
                }
            }
        }

        return false;
    }
};
