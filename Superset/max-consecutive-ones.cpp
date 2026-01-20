class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int count = 1;
        if (n == 1) return (nums[0] == 1) ? 1 : 0;
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