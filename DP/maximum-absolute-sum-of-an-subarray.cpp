class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int result = 0;
        int mini = 1e9;
        int sum = 0;
        for (int i = 0; i < n; i++){
            maxi = max(nums[i], maxi + nums[i]);
            mini = min(nums[i], mini + nums[i]);

            result = max({result, abs(maxi), abs(mini)});
        }

        return result;
    }
};