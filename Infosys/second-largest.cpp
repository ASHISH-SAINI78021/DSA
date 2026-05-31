class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        int maxii = INT_MIN;
        for (int i = 0; i < n; i++){
            if (arr[i] < maxi && arr[i] > maxii){
                maxii = arr[i];
            }
        }
        
        return maxii == INT_MIN ? -1 : maxii;
    }
};