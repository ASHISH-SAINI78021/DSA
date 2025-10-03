class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        vector<int> adj[numCourses + 1];
        queue<int> q;
        int visited = 0;
        for (int i = 0; i < arr.size(); i++){
            int u = arr[i][1];
            int v = arr[i][0];
            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses + 1, 0);
        for (int i = 0; i < numCourses; i++){
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }

        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0) q.push(i);
        }
        
        while (!q.empty()){
            auto front = q.front();
            visited++;
            q.pop();
            
            for (auto it : adj[front]){
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return !(numCourses != visited);
    }
};