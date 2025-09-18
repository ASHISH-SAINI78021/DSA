
class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &temp){
        // base case
        visited[node] = 1;
        temp.push_back(node);
        
        // solution for one case
        for (auto it : adj[node]){
            if (visited[it] == 0){
                dfs(it, adj, visited, temp);
            }
        }
    }
    vector<vector<int>> getComponents(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        vector<int> visited(v + 1, 0);
        vector<vector<int>> ans;
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for (int i = 0; i < v; i++){
            if (visited[i] == 0){
                vector<int> temp;
                dfs(i, adj, visited, temp);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }