class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> ans;
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++){
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }

        for (int i = 0; i < n; i++){
            if (indegree[i] == 0) ans.push_back(i);
        }

        return (ans.size() == 1) ? ans[0] : -1;
    }
};