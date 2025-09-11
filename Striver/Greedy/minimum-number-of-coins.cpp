class Solution {
  public:
    int findMin(int target) {
        vector<int> arr = {10,5,2,1};
        int n = arr.size();
        int i = 0;
        int count = 0;
        
        while (target >= 0 && i < n){
            if (arr[i] <= target){
                target -= arr[i];
                count++;
                continue ;
            }
            // count++;
            i++;
        }
        
        return count;
    }
};