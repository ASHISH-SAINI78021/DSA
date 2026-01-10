class Solution {
public:
    int solve(vector<int> &nums, int k){
        if (k < 0) return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int count = 0;
        int odd = 0;
        while (r < n){
            if (nums[r] & 1) odd++;
            while (odd > k){
                if (nums[l] & 1) odd--;
                l++;
            }
            count += r - l + 1;
            r++;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};


// exactly k subarrays = abs(k) - abs(k - 1)