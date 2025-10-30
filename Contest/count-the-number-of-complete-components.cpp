class Solution {
public:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, int &nodes, int &edge){
        // base case
        visited[node] = 1;
        nodes++;

        // solution for one case
        for (auto it : adj[node]){
            edge++;
            if (visited[it] == 0){
                dfs(it, visited, adj, nodes, edge);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        if (edges.size() == 0) return n;
        int count = 0;
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++){
            if (visited[i] == 0){
                int nodes = 0;
                int edge = 0;
                dfs(i, visited, adj, nodes, edge);
                edge = edge/2;
                if (edge == nodes*(nodes - 1)/2){
                    count++;
                }
            }
        } 

        return count;       
    }
};