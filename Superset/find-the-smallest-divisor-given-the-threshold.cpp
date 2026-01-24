class Solution {
public:
    bool isSafe(vector<int> &nums, int divisor, int threshold){
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += (nums[i] + divisor - 1)/divisor;
        }

        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (start <= end){
            int mid = start + (end  - start)/2;
            if (isSafe(nums, mid, threshold)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};

// 1 2 5 9    th = 6
// divisor = 1 -> divide the whole array by it and check its result <= threshold
// if I divide with max element then I can get atmax -> 1

// -> max divisor such that result <= threshold.

// // logic 
// divisor = 1 2 3 4 5 ------- max_element -> monotonic behavior -> B.S