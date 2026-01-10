class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            if (sum == goal) count++;
            if (mp.find(sum - goal) != mp.end()){
                count += mp[sum - goal];
            }
            mp[sum]++;
        }

        return count;
    }
};


// 1 0 1 0 1   goal = 2
// count = 2 + 2 = 4
// 1 -> 2
// 2 -> 1
// 3 -> 1