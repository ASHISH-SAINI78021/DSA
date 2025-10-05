class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited){
        // base case
        visited[node] = 1;

        // solution for one case
        for (auto it : adj[node]){
            if (visited[it] == 0) dfs(it, adj, visited);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++){
            long long x = bombs[i][0]; long long y = bombs[i][1]; long long r = bombs[i][2];
            for (int j = i + 1; j < n; j++){
                if (i == j) continue ;
                long long xi = bombs[j][0]; long long yi = bombs[j][1];
                long long r2 = bombs[j][2];
                long long k = (x - xi)*(x - xi) + (y - yi)*(y - yi);
                if (k <= r*r){
                    adj[i].push_back(j);
                }
                if (k <= r2*r2){
                    adj[j].push_back(i);
                }
            }
        }
        int maxBombs = 0;
        for (int i = 0; i < n; i++){
            vector<int> visited(n + 1, 0);
            int count = 0;
            dfs(i, adj, visited);
            for (int i = 0; i < n; i++){
                if (visited[i] == 1) count++;
            }
            maxBombs = max(maxBombs, count);
        }

        
        return maxBombs;
    }
};