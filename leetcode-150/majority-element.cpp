class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = -1;
        int count = 0;
        for (int i = 0; i < n; i++){
            if (count == 0){
                count = 1;
                candidate = nums[i];
            }
            else if (nums[i] == candidate) count++;
            else count--;
        }

        return candidate;
    }
};