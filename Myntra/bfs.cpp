class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        int v = adj.size();
        vector<int> visited(n + 1, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        
        while (!q.empty()){
            auto front = q.front(); q.pop();
            ans.push_back(front);
            for (auto it : adj[front]){
                if (visited[it] == 0){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        
        return ans;
    }
};