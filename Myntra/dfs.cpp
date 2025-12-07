class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans){
        visited[node] = 1;
        ans.push_back(node);
        
        for (auto it : adj[node]){
            if (visited[it] == 0){
                dfs(it, adj, visited, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> ans;
        vector<int> visited(v + 1, 0);
        for (int i = 0; i < v; i++){
            if (visited[i] == 0){
                dfs(i, adj, visited, ans);
            }
        }
        
        return ans;
    }
};