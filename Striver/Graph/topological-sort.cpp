
class Solution {
  private: 
    void dfs(int node , vector<int> &visited , vector<int> adj[] , stack<int> &st){
        visited[node] = true;
        
        for (auto it : adj[node]){
            if (visited[it] == 0){
                dfs(it , visited , adj , st);
            }
        }
        
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       vector<int> ans;
       vector<int> adj[V];
       
       for (int i = 0; i < edges.size(); i++){
           int u = edges[i][0];
           int v = edges[i][1];
           
           adj[u].push_back(v);
       }
       
       vector<int> visited(V , 0);
       stack<int> st;
       for (int i = 0; i < V; i++){
           if (visited[i] == 0){
               dfs(i , visited , adj , st);
           }
       }
       
       
       while (!st.empty()){
           ans.push_back(st.top()); 
           st.pop();
       }
       
       return ans;
    }
};

