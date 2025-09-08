// User function Template for C++

class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int n) {
        vector<int> ans;
        vector<int> brr = arr;
        sort(brr.begin(), brr.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for (int i = 0; i < n; i++){
            if (mp.find(brr[i]) == mp.end()) mp[brr[i]] = rank++;
        }
        
        for (int i = 0; i < n; i++){
            ans.push_back(mp[arr[i]]);
        }
        
        return ans;
    }
};
