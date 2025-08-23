class Solution {
public:
    int pivot(vector<int> &nums){
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (mid > 0 && nums[mid] < nums[mid - 1]){
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
    int bs(vector<int> &nums , int &target , int s , int e){
        int n = nums.size();

        while (s <= e){
            int mid = s + (e - s)/2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int p = pivot(nums);

        if (p == -1){
            return bs(nums , target , 0 , n - 1);
        }

        int ans1 = bs(nums , target , 0 , p - 1);
        int ans2 = bs(nums , target , p , n - 1);

        if (ans1 != -1){
            return ans1;
        }
        else {
            return ans2;
        }
    }
};