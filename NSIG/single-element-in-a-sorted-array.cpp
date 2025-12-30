class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start < end){
            int mid = start + (end - start)/2;
            bool isLeftOk = (mid % 2 == 0 && nums[mid] == nums[mid + 1]);
            bool isRightOk = (mid % 2 == 1 && nums[mid] == nums[mid - 1]);
            if (isLeftOk || isRightOk){
                start = mid + 1;
            }
            else end = mid;
        }

        return nums[start];
    }
};


// 1 1 2 3 3 4 4 8 8
// 0 1 2 3 4 5 6 7 8