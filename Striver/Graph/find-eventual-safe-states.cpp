class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<vector<int>> adj(graph.size());
        vector<int> indegree(graph.size(), 0);
        queue<int> q;
        for (int i = 0; i < graph.size(); i++){
            for (auto it : graph[i]){
                adj[it].push_back(i);
            }
        }
        for (int i = 0; i < n; i++){
            for (auto it : adj[i]) indegree[it]++;
        }
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()){
            auto front = q.front(); q.pop();
            ans.push_back(front);
            for (auto it : adj[front]){
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};