class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        int maxP = nums[0];

        for (int i = 1; i < n; i++){
            if (nums[i] < 0) swap(maxi, mini);
            maxi = max(nums[i], nums[i]*maxi);
            mini = min(nums[i], nums[i]*mini);
            maxP = max(maxP, maxi);
        }

        return maxP;
    }
};