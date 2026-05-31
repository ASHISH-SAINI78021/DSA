class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = -1; 
        int j = n - 1;

        for (int k = 0; k < n; k++){
            if (nums[k] == 0){
                i = k; break;
            } 
        }
        if (i  == -1) return ;
        for (int j = i; j < n; j++){
            if (nums[j] != 0){
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};


// 0 1 0 3 12
// 1 3 12 0 0