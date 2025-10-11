class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0; int r = 2;
        int maxi = 2;
        while (r < n){
            if (nums[r - 1] + nums[r - 2] == nums[r]){
                maxi = max(maxi, r - l + 1);
                r++;
            }
            else {
                r++;
                l = r - 2;
            }
        }

        return maxi;
    }
};©leetcode