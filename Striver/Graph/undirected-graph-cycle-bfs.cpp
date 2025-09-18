class Solution {
  public:
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
        
        queue<pair<int, int>> q;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {  // ✅ Only start BFS from unvisited nodes
                q.push({i, -1});
                visited[i] = 1;
            
                while (!q.empty()) {
                    auto [child, parent] = q.front();
                    q.pop();

                    for (auto it : adj[child]) {
                        if (!visited[it]) {
                            visited[it] = 1;  // mark before push
                            q.push({it, child});
                        }
                        else if (it != parent) {
                            return true;      // cycle found
                        }
                    }
                }
            }
        }

        return false;
    }
};
