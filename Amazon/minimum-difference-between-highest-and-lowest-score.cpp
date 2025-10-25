class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int mini = 1e9;
        while (r < n){
            if (r - l + 1 == k){
                int minValue = *min_element(nums.begin() + l, nums.begin() + r + 1);
                int maxValue = *max_element(nums.begin() + l, nums.begin() + r + 1);
                mini = min(mini, maxValue - minValue);
                l++;
            }
            r++;
        }

        return mini;
    }
};