class DisjointSet {
    vector<int> parent, rank;
    public : 
        DisjointSet(int n){
            rank.resize(n + 1, 0);
            parent.resize(n + 1, 0);
            for (int i = 0; i <= n; i++) parent[i] = i;
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
            if (rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
            else if (rank[ulp_v] > rank[ulp_u]) parent[ulp_u] = ulp_v;
            else {
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }  
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        int nC = 0;
        int extraCnt = 0;
        DisjointSet st(n);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if (st.findUPar(u) == st.findUPar(v)) extraCnt++;
            else st.unionByRank(u, v);
        }
        // count the number of components
        for (int i = 0; i < n; i++) if (st.findUPar(i) == i) nC++;
        int ans = nC - 1;
        if (extraCnt >= ans) return ans;
        else return -1;
    }
};