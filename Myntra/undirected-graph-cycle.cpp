class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V + 1, 0);
        using T = pair<int, int>;
        queue<T> q;
        for (int i = 0; i < V; i++){
            if (visited[i] == 0){
                q.push({i, -1});
                visited[i] = 1;
                
                while (!q.empty()){
                    auto front = q.front(); q.pop();
                    int node = front.first;
                    int parent = front.second;
                    
                    for (auto it : adj[node]){
                        if (visited[it] == 0){
                            q.push({it, node});
                            visited[it] = 1;
                        }
                        else if (it != parent){
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};