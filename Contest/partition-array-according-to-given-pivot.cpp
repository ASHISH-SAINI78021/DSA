class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] == pivot) count++;
        }
        for (int i = 0; i < n; i++){
            if (nums[i] < pivot){
                ans.push_back(nums[i]);
            }
        }
        for (int i = 0; i < count; i++){
            ans.push_back(pivot);
        }
        for (int i = 0; i < n; i++){
            if (nums[i] > pivot) ans.push_back(nums[i]);
        }

        return ans;
    }
};