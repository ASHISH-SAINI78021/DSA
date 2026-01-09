class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int largest = INT_MIN;
        int secondLargest = largest;
        int index = -1;
        for (int i = 0; i < n; i++){
            if (largest < arr[i]){
                largest = arr[i];
                index = i;
            }
        }
        
        for (int i = 0; i < n; i++){
            if (arr[i] > secondLargest && arr[i] < largest && index != i){
                secondLargest = arr[i];
            }
        }
        
        return secondLargest == INT_MIN ? -1 : secondLargest;
    }
};