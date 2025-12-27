class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        int index = -1;
        for (int i = 0; i < n; i++){
            if (maxi < arr[i]){
                index = i;
                maxi = arr[i];
            }
        }
        
        int second_maxi = INT_MIN;
        for (int i = 0; i < n; i++){
            if (second_maxi < arr[i] && arr[i] != maxi && i != index){
                second_maxi = arr[i];
            }
        }
        
        return second_maxi;
    }
};