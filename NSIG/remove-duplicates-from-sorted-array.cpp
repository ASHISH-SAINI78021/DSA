class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        int k = 1;
        for (int i = 1; i < n; i++){
            if (nums[i - 1] != nums[i]){
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

// nums = 0 0 1 1 1 2 2 3 3 4
// k = 1
// 0 1 2 3 4 _ ....