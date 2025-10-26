class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        long long ans = 0;
        for (auto it : mp){
            if (it.second % k == 0){
                ans += (long long)it.first * it.second;
            }
        }

        return ans;
    }
};