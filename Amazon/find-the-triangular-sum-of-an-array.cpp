class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1){
            vector<int> temp;
            for (int i = 1; i < nums.size(); i++){
                int value = (nums[i] + nums[i - 1]) % 10;
                temp.push_back(value);
            }
            nums = temp;
        }

        return nums[0];
    }
};