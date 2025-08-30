class Solution {
public:
    bool solve(vector<int> &nums, int &threshold, int divisor){
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
            int mid = start + (end - start)/2;
            if (solve(nums, threshold, mid)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};