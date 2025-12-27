class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int maxi = 1;
        if (n == 1 && nums[0] == 1) return 1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == 0) return 0;

        for (int i = 1; i < n; i++){
            if (nums[i] == nums[i - 1] && nums[i] == 1){
                count++;
                maxi = max(maxi, count);
            }
            else count = 1;
        }

        return maxi;
    }
};