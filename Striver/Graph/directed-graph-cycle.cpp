class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        queue<int> q;
        int count = 0;
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < V; i++){
            for (auto it : adj[i]) indegree[it]++;
        }
        for (int i = 0; i < V; i++){
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()){
            auto front = q.front(); q.pop();
            count++;
            for (auto it : adj[front]){
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        
        return count != V;
    }
};