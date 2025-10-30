class Solution {
public:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj){
        // base case
        visited[node] = 1;

        // solution for one case
        for (auto it : adj[node]){
            if (visited[it] == 0){
                dfs(it, visited, adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        dfs(0, visited, adj);

        for (int i = 0; i < n; i++) if (visited[i] == 0) return false;

        return true;
    }
};