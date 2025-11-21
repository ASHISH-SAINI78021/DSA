class Solution {
  public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> ans(indices.size(), 0);
        for (int i = 0; i < indices.size(); i++){
            int element = arr[indices[i]];
            for (int j = indices[i]; j < n; j++){
                if (element < arr[j]) ans[i]++;
            }
        }
        
        return ans;
    }
};