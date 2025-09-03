class Solution {
public:
    void solve(vector<int> &arr, int k, int target, int index, vector<int> &temp, vector<vector<int>> &ans){
        // base case
        if (target == 0 && k == 0){
            ans.push_back(temp);
            return ;
        }
        if (index >= arr.size()) return ;
        
        // solution for one case
        temp.push_back(arr[index]);
        solve(arr, k - 1, target - arr[index], index + 1, temp, ans);
        temp.pop_back();
        solve(arr, k, target, index + 1, temp, ans);
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> ans;
        int index = 0;
        vector<int> temp;
        vector<int> arr;
        for (int i = 1; i <= 9; i++) arr.push_back(i);

        solve(arr, k, target, index, temp, ans);

        return ans;
    }
};