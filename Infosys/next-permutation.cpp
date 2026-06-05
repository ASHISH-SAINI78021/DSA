class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int index = -1;
            for (int i = n - 2; i >= 0; i--){
                if (nums[i] < nums[i + 1]){
                    index = i; 
                    break;
                }
            }
    
            if (index == -1){
                reverse(nums.begin(), nums.end());
                return ;
            }
            
            for (int i = n - 1; i < n; i--){
                if (nums[i] > nums[index]){
                    swap(nums[i], nums[index]);
                    break;
                }
            }
    
            reverse(nums.begin() + index + 1, nums.end());
            
        }
    };
    
    
    
    
    // 1 3 7 4 2 1
    
    // 1 3 1 2 4 7
    
    // 7 4 3 1