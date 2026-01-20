class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        if (n == 1 || n == 2) return true;
        if (nums[0] < nums[n - 1]) count++;
        for (int i = 1; i < n; i++){
            if (nums[i - 1] > nums[i]) count++;
            if (count > 1) return false;
        }

        return true;
    }
};