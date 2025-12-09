class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
            if (sum == k) maxi = max(maxi, i + 1);
            else {
                if (mp.find(sum - k) != mp.end()){
                    int len = i - mp[sum - k];
                    maxi = max(maxi, len);
                }
            }
            if (mp.find(sum) == mp.end()) mp[sum] = i;
        }
        
        return maxi;
    }
};