class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int prefix = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            prefix += arr[i];
            if (prefix == 0) maxLen = max(maxLen, i + 1);
            if (mp.find(prefix) != mp.end()){
                maxLen = max(maxLen, i - mp[prefix]);
            }
            else {
                mp[prefix] = i;
            }
        }
        
        return maxLen;
    }
};