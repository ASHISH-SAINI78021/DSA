class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++){
            sum += nums[i];
            int rem = sum - k;
            if (mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[sum]++;
        }

        return count;
    }
};