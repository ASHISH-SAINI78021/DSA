class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n){
            if (i > 0 && nums[i] == nums[i - 1]){
                i++;
            }
            else {
                int j = i + 1;
                int k = n - 1;
                while (j < k){
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0){
                        ans.push_back({nums[i], nums[j], nums[k]});
                        j++; k--;
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    }
                    else if (sum > 0){
                        k--;
                    }
                    else {
                        j++;
                    }
                }
                i++;
            }
        }

        return ans;
    }
};