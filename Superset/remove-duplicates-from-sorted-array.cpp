class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        if (n == 1) return 1;

        for (int i = 1; i < n; i++){
            if (nums[i - 1] != nums[i]){
                nums[k++] = nums[i]; 
            }
        }

        return k;
    }
};