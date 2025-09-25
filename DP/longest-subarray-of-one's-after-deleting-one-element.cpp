class Solution {
public:
    int solve(vector<int> &nums, int index, int k){
        // base case
        if ()

        // solution for one case
        int ans1 = 0;
        int ans2 = 0;
        if (nums[index] == 1){
            ans1 = 1 + solve(nums, index + 1, 1);
        }
        else {
            ans2 = solve(nums, index + 1, 0);
        }

        return max(ans1, ans2);
    }
    int longestSubarray(vector<int>& nums) {
        int n  = nums.size();
        int index = 0;
        int k = 1;
        int ans = solve(nums, index, k);

        return ans;
    }
};