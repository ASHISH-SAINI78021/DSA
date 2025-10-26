class Solution {
public:
    void dfs(int node, vector<int> &visited, vector<vector<pair<int,int>>> &adj){
        // base case
        visited[node] = 1;

        // solution for one case
        for (auto it : adj[node]){
            if (visited[it.first] == 0){
                dfs(it.first, visited, adj);
            }
        }
    }
    bool isSafe(vector<vector<int>> &edges, int mid, int k, int n){
        vector<vector<pair<int,int>>> adj(n);
        vector<int> visited(n, 0);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if (wt <= mid){
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++){
            if (visited[i] == 0){
                dfs(i, visited, adj);
                count++;
            }
        }

        return count <= k;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int maxWeight = 0;
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            maxWeight = max(maxWeight, wt);
        }

        int ans = 0;
        int start = 0;
        int end = maxWeight;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (isSafe(edges, mid, k, n)){
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};