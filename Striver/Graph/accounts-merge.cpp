class DisjointSet {
    private:
        vector<int> parent , rank;
    public:
        DisjointSet(int n){
            parent.resize(n + 1 , 0);
            rank.resize(n + 1 , 0);
            for (int i = 0; i <= n; i++){
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if (node == parent[node]){
                return node;
            }

            return node = findUPar(parent[node]);
        }

        void unionByRank(int u , int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if (ulp_u == ulp_v) return ;

            if (rank[ulp_u] > rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] > rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_u] = ulp_v;
                rank[ulp_u]++;
            }
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> ans;
        unordered_map<string, int> mp;
        DisjointSet st(n);
        for (int i = 0; i < n; i++){
            for (int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else {
                    st.unionByRank(i, mp[mail]);
                }
            }
        }

        vector<vector<string>> mergeMail(n);
        for (auto it : mp){
            string mail = it.first;
            int node = it.second;
            node = st.findUPar(node);
            mergeMail[node].push_back(mail);
        }
        for (int i = 0; i < n; i++){
            if (mergeMail[i].empty()) continue ;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};











