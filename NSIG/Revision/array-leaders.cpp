class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr;
        vector<int> ans;
        int maxi = arr[n - 1];
        ans.push_back(maxi);
        for (int i = n - 2; i >= 0; i--){
            if (maxi <= arr[i]){
                maxi = arr[i];
                ans.push_back(maxi);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};