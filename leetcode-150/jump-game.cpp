class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int maxi = 0;
        if (n == 1) return true;
        while (i < n){
            maxi = max(maxi, nums[i]);
            if (maxi == 0 && i < n - 1) return false;
            maxi--;
            i++;
        }

        return true;
    }
};