class Solution {
public:
    int solve1(vector<int> &nums, int index, vector<int> &dp){
        // base case
        if (index >= nums.size()) return 0;
        if (dp[index] != -1) return dp[index];

        // solution for one case
        int include = nums[index] | solve1(nums, index + 1, dp);
        int exclude = solve1(nums, index + 1, dp);

        return dp[index] = max(include, exclude);
    }
    int solve2(vector<int> &nums, int index, int temp, int target, vector<vector<int>> &dp){
        // base case
        if (index == nums.size()){
            return target == temp ? 1 : 0;
        }
        if (dp[index][temp] != -1) return dp[index][temp];

        // solution for one case
        int include = solve2(nums, index + 1, temp | nums[index], target, dp);
        int exclude = solve2(nums, index + 1, temp, target, dp);

        return dp[index][temp] = include + exclude;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        vector<int> dp1(n + 1, -1);
        int target = solve1(nums, index, dp1);
        int temp = 0;
        vector<vector<int>> dp2(n + 1, vector<int>(1 << 17, -1));
        int ans = solve2(nums, index, temp, target, dp2);

        return ans;
    }
};