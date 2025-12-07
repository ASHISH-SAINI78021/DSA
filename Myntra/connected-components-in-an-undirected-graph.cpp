class Solution {
  public:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, vector<int> &result){
        visited[node] = 1;
        result.push_back(node);
        for (auto it : adj[node]){
            if (visited[it] == 0){
                dfs(it, visited, adj, result);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V + 1, 0);
        for (int i = 0; i < V; i++){
            if (visited[i] == 0){
                vector<int> result;
                dfs(i, visited, adj, result);
                ans.push_back(result);
            }
        }
        
        return ans;
    }
};
