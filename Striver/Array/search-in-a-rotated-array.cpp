class Solution {
public:
    int pivot(vector<int> &nums){
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (mid > 0 && nums[mid - 1] > nums[mid]){
                return mid;
            }
            if (mid + 1 < n && nums[mid] > nums[mid + 1]){
                return mid + 1;
            }

            if (nums[start] < nums[mid]){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return -1;
    }
    int bs(vector<int> &nums, int start, int end, int &target){
        while (start <= end){
            int mid = start + (end - start)/2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int p = pivot(nums);    
        if (p == -1){
            return bs(nums, 0, n - 1, target);
        }
        if (nums[0] <= target && target <= nums[p - 1]){
            int ans1 = bs(nums, 0, p - 1, target);
            if (ans1 != -1) return ans1;
        }

        return bs(nums, p, n - 1, target);
    }
};