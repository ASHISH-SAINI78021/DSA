

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        if (n == 0) return ans;
        int maxi = arr[n - 1];
        ans.push_back(maxi);
        
        for (int i = n - 2; i >= 0; i--){
            if (arr[i] >= arr[i + 1] && arr[i] >= maxi){
                maxi = arr[i];
                ans.push_back(arr[i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};