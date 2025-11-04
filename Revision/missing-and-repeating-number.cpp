class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int missing = -1;
        int twice = -1;
        for (int i = 0; i < n; i++){
            int index = abs(arr[i]);
            if (arr[index - 1] < 0) twice = index;
            else {
                arr[index - 1] = -arr[index - 1];
            }
        }
        
        // for (auto it : arr) cout << it << " ";
        
        for (int i = 0; i < n; i++){
            if (arr[i] > 0){
                missing = i + 1;
            }
        }
        
        return {twice, missing};
    }
};