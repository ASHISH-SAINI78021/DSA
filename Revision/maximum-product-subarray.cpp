class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < n; i++){
            if (nums[i] < 0){
                swap(mini, maxi);
            }
            maxi = max(nums[i], maxi * nums[i]);
            mini = min(nums[i], mini * nums[i]);
            result = max(result, maxi);
        }

        return result;
    }
};