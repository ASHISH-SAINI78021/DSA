class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        if (n == 1) return true;
        int i = 0;
        while (maxi-- && i < n){
            maxi = max(maxi, nums[i]);
            i++;
        }

        return i == n;
    }
};