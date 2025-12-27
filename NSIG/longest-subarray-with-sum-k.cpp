class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 1) return arr[0] == k;
        unordered_map<long long, int> mp;
        long long sum = 0;
        int count = 0;
        long long maxi = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
            if (sum == k){
                if (i + 1 > maxi) maxi = i + 1;
            }
            if (mp.find(sum - k) != mp.end()){
                if (i - mp[sum - k] > maxi) maxi = i - mp[sum - k];
            }
            
            if (mp.find(sum) == mp.end()) mp[sum] = i;
        }
        
        return maxi;
    }
};