class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (nums[mid] == target){
                return true;
            }

            if (nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
                continue ;
            }
            
            if (nums[mid] >= nums[start]){
                // left sorted part
                if (nums[start] <= target && target <= nums[mid]){
                    end = mid - 1;
                }
                else start = mid + 1;
            }
            else {
                // right sorted part
                if (nums[mid] <= target && target <= nums[end]){
                    start = mid + 1;
                }
                else end = mid - 1;
            }
        }

        return false;
    }
};