class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V , 0);
	    queue<int> q;
	    for (int i = 0; i < V; i++){
	        for (it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for (int i = 0; i < V; i++){
	        if (indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    
	    while (!q.empty()){
	        int front = q.front();
	        q.pop();
	        topo.push_back(front);
	        
	        for (auto it : adj[front]){
	            indegree[it]--;
	            if (indegree[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    
	    return topo;
	}
};