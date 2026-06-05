class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int low = 0; int mid = 0; int high = n - 1;
    
            while (mid <= high){
                if (nums[mid] == 2){
                    swap(nums[mid], nums[high]);
                    high--;
                }
                else if (nums[mid] == 1){
                    mid++;
                }
                else {
                    swap(nums[mid], nums[low]);
                    low++;
                    mid++;
                }
            }
        }
    };
    
    
    // 2 0 2 1 1 0
    // high = n - 1; -> it is used to point 2
    // low = 0; -> it is used to point 0
    // mid = 0; -> it is used to point 1