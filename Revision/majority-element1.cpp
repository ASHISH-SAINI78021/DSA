class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate = -1;
        for (int i = 0; i < n; i++){
            if (count == 0){
                count = 1;
                candidate = nums[i];
            }
            else if (candidate == nums[i]){
                count++;
            }
            else {
                count--;
            }
        }

        return candidate;
    }
};