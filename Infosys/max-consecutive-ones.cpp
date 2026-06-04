class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return nums[0] == 1 ? 1 : 0;
            int maxi = 0;
            
    
            int count = 0;
            for (int i = 0; i < n; i++){
                if (i > 0 && nums[i] == nums[i - 1] && nums[i] == 1){
                    count++;
                } 
                else if (nums[i] == 1) count = 1;
                else count = 0;
                maxi = max(maxi, count);
            }
    
            
            return maxi;
        }
    };