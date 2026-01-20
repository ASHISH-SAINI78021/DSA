class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int maxi = 0;
        int index = -1;
        for (int i = 0; i < n; i++){
            if (arr[i] > maxi){
                maxi = arr[i];
                index = i;
            }
        }
        
        int secondLargest = -1;
        for (int i = 0; i < n; i++){
            if (secondLargest < arr[i] && arr[i] < maxi && i != index){
                secondLargest = arr[i];
            }
        }
        
        return secondLargest;
    }
};