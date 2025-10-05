class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        long long Xor = 0;
        for (int i = 0; i < n; i++){
            Xor = nums[i]^Xor;
        }

        if (Xor == 0){
            long long totalXor = accumulate(nums.begin(), nums.end(), 0LL);
            if (totalXor == 0) return 0;
            else return n - 1;
        }
        else return n;
    }
};©leetcode