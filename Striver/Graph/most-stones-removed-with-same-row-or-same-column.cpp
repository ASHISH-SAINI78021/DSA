class DisjointSet {
    vector<int> rank, parent;
    public : 
        DisjointSet(int n){
            rank.resize(n + 1, 0);
            parent.resize(n + 1, 0);
            for (int i = 0; i <= n; i++) parent[i] = i;
        }
        int findUPar(int node){
            if (node == parent[node]) return node;
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;
        for (auto it :  stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }

        unordered_map<int, int> mp;
        DisjointSet st(maxrow + maxcol + 1);
        for (int i = 0; i < n; i++){
            int u = stones[i][0];
            int v = stones[i][1] + maxrow + 1;
            st.unionByRank(u, v);
            mp[u] = 1;
            mp[v] = 1;
        }
        int cnt = 0;
        for (auto it : mp){
            if (st.findUPar(it.first) == it.first) cnt++;
        }

        return n - cnt;
    }
};