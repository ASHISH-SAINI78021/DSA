class Solution {
public:
    long long solve(vector<int> &nums, long long target){
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        long long ans = 0;
        while (left < right){
            int sum = nums[left] + nums[right];
            if (sum <= target){
                ans += right - left;
                left++;
            }
            else right--;
        }

        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());
        long long upperCount = solve(nums, static_cast<long long>(upper));
        long long lowerCount = solve(nums, static_cast<long long>(lower) - 1);


        return upperCount - lowerCount;
    }
};