class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        if (it1 == nums.end() || *it1 != target) return {-1, -1};  // target not found

        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        int first = it1 - nums.begin();
        int last = it2 - nums.begin() - 1; // because upper_bound points to >target

        return {first, last};
    }
};
