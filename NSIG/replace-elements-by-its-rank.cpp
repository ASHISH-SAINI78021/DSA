class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int n) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> mp;
        int rank = 1;

        for (int i = 0; i < n; i++){
            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = rank;
                rank++;
            }
        }

        vector<int> ans;
        for (int x : arr){
            ans.push_back(mp[x]);
        }

        return ans;
    }
};
