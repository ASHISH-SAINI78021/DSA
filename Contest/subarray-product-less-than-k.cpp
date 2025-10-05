class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        long long product = 1;
        int count = 0;
        if (k == 0 || k == 1) return 0;
        while (r < n){
            product = product*nums[r];
            while (product >= k && l < n){
                product = product / nums[l];
                l++;
            }
            if (product < k) count += (r - l + 1 > 0) ? r - l + 1 :0;
                
            r++;
        }

        return count;
    }
};