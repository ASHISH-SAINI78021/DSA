class Solution {
public:
    void solve(vector<int> &candidates, int target, int index, vector<int> &temp, vector<vector<int>> &ans){
        // base case
        if (target < 0) return ;
        if (target == 0){
            ans.push_back(temp);
            return ;
        }
        if (index >= candidates.size()){
            return ;
        }

        // solution for one case
        if (candidates[index] <= target){
            temp.push_back(candidates[index]);
            solve(candidates, target - candidates[index], index, temp, ans);
            temp.pop_back();
        }
        solve(candidates, target, index + 1, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        vector<int> temp;

        int index = 0;
        solve(candidates, target, index, temp, ans);
        
        return ans;
    }
};