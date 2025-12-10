class Solution {
public:
    int solve(vector<int> &nums, int index, int target){
        // base case 
        if (index >= nums.size() && target == 0) return 1;
        if (index >= nums.size()) return 0;

        int ans1 = solve(nums, index + 1, target - nums[index]);

        int ans2 = solve(nums, index + 1, target + nums[index]);

        return ans1 + ans2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int index = 0;
        int ans = solve(nums, index, target);

        return ans;
    }
};