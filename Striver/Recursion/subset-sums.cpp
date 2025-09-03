class Solution {
  public:
    void solve(vector<int> &arr, int index, int sum, vector<int> &ans){
        // base case
        if (index >= arr.size()){
            ans.push_back(sum);
            return ;
        }
        
        
        // solution for one case
        solve(arr, index + 1, sum + arr[index], ans);
        solve(arr, index + 1, sum, ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        int sum = 0;
        int index = 0;
        solve(arr, index, sum, ans);
        
        return ans;
    }
};