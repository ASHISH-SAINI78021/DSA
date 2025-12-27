class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++){
            mp[a[i]]++;
        }
        for (int i = 0; i < m; i++){
            mp[b[i]]++;
        }
        for (auto it : mp){
            ans.push_back(it.first);
        }
        
        return ans;
    }
};