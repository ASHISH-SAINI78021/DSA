class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<vector<int>> &ans, vector<int> temp){
        // base case
        int n = adj.size();
        temp.push_back(node);
        if (node == n - 1){
            ans.push_back(temp);
            return ;
        }

        // solution for one case
        for (auto it : adj[node]){
            if (visited[it] == 0){
                dfs(it, adj, visited, ans, temp);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> temp;
        vector<int> visited(n, 0);
        dfs(0, graph, visited, ans, temp);
        
        return ans;
    }
}