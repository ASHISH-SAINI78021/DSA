// User function Template for C++
class Solution {
  public:
    void dfs(int node, vector<vector<pair<int,int>>> &adj, vector<int> &visited, stack<int> &st){
        // base case 
        visited[node] = 1;
        
        // solution for one case
        for (auto it : adj[node]){
            if (visited[it.first] == 0) dfs(it.first, adj, visited, st);
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<int> dist(V, INT_MAX);
        stack<int> st;
        vector<vector<pair<int, int>>> adj(V);
        vector<int> visited(V);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        for (int i = 0; i < V; i++){
            if (visited[i] == 0) dfs(i, adj, visited, st);
        }
        dist[0] = 0;
        while (!st.empty()){
            auto top = st.top(); st.pop();
            if (dist[top] != INT_MAX){
                for (auto it : adj[top]){
                    if (dist[top] + it.second < dist[it.first]){
                        dist[it.first] = dist[top] + it.second;
                    }
                }
            }
        }
        
        for (int i = 0; i < V; i++) if (dist[i] == INT_MAX) dist[i] = -1;
        
        return dist;
    }
};
