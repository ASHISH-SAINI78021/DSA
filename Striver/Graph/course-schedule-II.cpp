class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& arr) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for (int i = 0; i < arr.size(); i++){
            int u = arr[i][0];
            int v = arr[i][1];
            adj[v].push_back(u);
        }
        for (int i = 0; i < numCourses; i++){
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }
        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()){
            auto front = q.front();q.pop();
            ans.push_back(front);
            for (auto it : adj[front]){
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return (ans.size() == numCourses) ? ans : vector<int> ();
    }
};