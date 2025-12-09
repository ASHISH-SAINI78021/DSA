class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 && k == nums[0]) return 1;
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            if (sum == k) count++;
            
                if (mp.find(sum - k) != mp.end()){
                    count += mp[sum - k];
                }
            mp[sum]++;
        }

        return count;
    }
};