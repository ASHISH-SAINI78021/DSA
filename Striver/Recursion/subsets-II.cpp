class Solution {
public:
    void solve(vector<int> &nums, int index, vector<int> &temp, vector<vector<int>> &ans){
        // base case
        ans.push_back(temp);

        // solution for one case
        
        for (int i = index; i < nums.size(); i++){
            if (i > index && nums[i] == nums[i - 1]) continue ;
            temp.push_back(nums[i]);
            solve(nums, i + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int index = 0;
        sort(nums.begin(), nums.end());

        vector<int> temp;
        solve(nums, index, temp, ans);

        return ans;
    }
};