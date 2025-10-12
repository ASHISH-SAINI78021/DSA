class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 0;
        mp[1] = 1;
        mp[2] = 1;
        int count = 0;
        for (int i = 0; i < n; i++){
            int rem = nums[i] % 3;
            count += mp[rem];
        }

        return count;
    }
};