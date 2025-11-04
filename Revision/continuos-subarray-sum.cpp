class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;

        for (int i = 0; i < n; i++){
            sum += nums[i];
            int required = sum % k;
            if (mp.find(required) != mp.end()){
                if (i - mp[required] > 1) return true;
            }
            else {
                mp[required] = i;
            }
        }

        return false;
    }
};