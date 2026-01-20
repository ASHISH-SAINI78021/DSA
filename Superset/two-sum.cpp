class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            if (mp.find(target - nums[i]) != mp.end()){
                return {i, mp[target - nums[i]]};
            }

            if (mp.find(nums[i]) == mp.end()) mp[nums[i]] = i;
        }

        return ans;
    }
};


// nums = 2 7 11 15
// target = 9
// ans -> 0 1
// 2 + 7 = 9

// Brute Force
// T.C -> O(n*n)
// S.C -> O(1)

// Optimal Approach
// T.C -> O(n)
// S.C -> O(n);