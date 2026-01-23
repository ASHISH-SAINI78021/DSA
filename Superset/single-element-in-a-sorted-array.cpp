class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start < end){
            int mid = start + (end - start)/2;
            bool leftOk = (mid % 2 == 1 && nums[mid] == nums[mid - 1]);
            bool rightOk = (mid % 2 == 0 && nums[mid] == nums[mid + 1]);

            if (leftOk || rightOk){
                start = mid + 1;
            }
            else end = mid;
        }

        return nums[start];
    }
};