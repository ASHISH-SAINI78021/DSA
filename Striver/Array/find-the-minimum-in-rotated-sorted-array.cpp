class Solution {
public:
    int pivot(vector<int> &nums){
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (mid > 0 && nums[mid - 1] > nums[mid]) return mid;
            if (mid + 1 < n && nums[mid] > nums[mid + 1]) return mid + 1;
            if (nums[start] <= nums[mid]) start = mid + 1;
            else end = mid - 1;
        }

        return -1;
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int p = pivot(nums);
        if (p == -1) return nums[0];

        return nums[p];
    }
};