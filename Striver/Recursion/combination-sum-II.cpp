class Solution {
public:
    void solve(vector<int> &candidates, int target, int index, vector<int> &temp, vector<vector<int>> &ans){
        // base case
        if (target == 0){
            ans.push_back(temp);
            return ;
        }
        if (index >= candidates.size() || target < 0) return ;

        // solution for one case
        for (int i = index; i < candidates.size(); i++){
            if (i > index && candidates[i] == candidates[i - 1]) continue ;
            if (candidates[i] > target) break; // prunning
            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, index, temp, ans);

        return ans;
    }
};