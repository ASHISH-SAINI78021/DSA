class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return -1;
        if (n == 1) return arr[0];
        int firstLargest = arr[0];
        int secondLargest = INT_MIN;
        for (int i = 0; i < n; i++){
            if (arr[i] > firstLargest){
                secondLargest = firstLargest;
                firstLargest = arr[i];
            }
            else if (arr[i] > secondLargest && firstLargest != arr[i]){
                secondLargest = arr[i];
            }
        }
        
        return secondLargest == INT_MIN ? -1 : secondLargest;
    }
};