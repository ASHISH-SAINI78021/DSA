class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualSum = accumulate(nums.begin(), nums.end(), 0);
        int sum = n*(n + 1)/2;

        return abs(sum - actualSum);
    }
};