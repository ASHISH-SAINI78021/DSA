class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = 0;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                ans = mid + 1;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};