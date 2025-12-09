class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for (int i = n - 2; i < n; i++){
            if (nums[i] < nums[i + 1]){
                index = i;
                break;
            }
        }
        
        if (index == -1){
            // 4,3,2,1
            reverse(nums.begin(), nums.end());
            return ;
        }

        for (int i = n - 1; i >= 0; i--){
            if (nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
};