class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 2){
            vector<int> ans;
            for (int i = 0; i < n; i++) ans.push_back(i);
            return ans;
        }
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            for (auto it : adj[i]) if (degree[it] == 1) q.push(it); 
        }

        int remainingNode = n;
        while (remainingNode > 2){
            int layerSize = q.size();
            remainingNode -= layerSize;
            for (int i = 0; i < layerSize; i++){
                int leaf = q.front(); q.pop();
                for (auto it : adj[leaf]){
                    degree[it]--;
                    if (degree[it] == 1) q.push(it);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()){
            int front = q.front(); q.pop();
            ans.push_back(front);
        }

        return ans;
    }
};