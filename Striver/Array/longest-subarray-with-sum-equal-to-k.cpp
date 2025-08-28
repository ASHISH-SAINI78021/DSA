class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int sum = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
            if (sum == k){
                maxi = max(maxi, i + 1);
            }
            
            int rem = sum - k;
            if (mp.find(rem) != mp.end()){
                int len = i - mp[rem];
                maxi = max(maxi, len);
            }
            
            if (mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        
        return maxi;
    }
};