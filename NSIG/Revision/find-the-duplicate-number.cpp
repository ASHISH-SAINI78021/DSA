class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int index = abs(nums[i]);
            if (nums[index - 1] < 0){
                return index;
            }
            else {
                nums[index - 1] = -nums[index - 1];
            }
        }

        return -1;
    }
};