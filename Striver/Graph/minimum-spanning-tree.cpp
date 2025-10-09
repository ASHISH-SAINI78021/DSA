class DisjointSet {
    vector<int> parent, rank;
    public : 
        DisjointSet(int n){
            rank.resize(n + 1, 0);
            parent.resize(n + 1, 0);
            for (int i = 1; i <= n; i++) parent[i] = i;
        }
        int findUPar(int node){
            // base case
            if (node == parent[node]) return node;
            
            // solution for one case
            return parent[node] = findUPar(parent[node]);
        }
        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return ;
            if (rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
            else if (rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
            else {
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
};
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& arr) {
        vector<pair<int, pair<int,int>>> edges;
        for (int i = 0; i < arr.size(); i++){
            int u = arr[i][0];
            int v = arr[i][1];
            int wt = arr[i][2];
            if (u < v) edges.push_back({wt, {u, v}});
        }
        sort(edges.begin(), edges.end());
        DisjointSet st(V);
        int mst = 0;
        for (auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (st.findUPar(u) != st.findUPar(v)){
                mst += wt;
                st.unionByRank(u, v);
            }
        }
        
        return mst;
    }
};