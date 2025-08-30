class Solution {
  public:
    bool isSafe(vector<int> &arr, int pages, int k){
        int n = arr.size();
        int currentSum = 0;
        int count = 1;
        
        for (int i = 0; i < n; i++){
            if (arr[i] > pages) return false;
            if (arr[i] + currentSum > pages){
                count++;
                currentSum = arr[i];
            }
            else {
                currentSum += arr[i];
            }
        }
        
        return count <= k;
    }
    int findPages(vector<int> &arr, int k) {
       int n = arr.size();
       if (k > n) return -1;
       int mini = *min_element(arr.begin(), arr.end());
       int maxi = accumulate(arr.begin(), arr.end(), 0);
       
       int start = mini;
       int end = maxi;
       int result = -1;
       
       while (start <= end){
           int mid = start + (end - start)/2;
           if (isSafe(arr, mid, k)){
               result = mid;
               end = mid - 1;
           }
           else{
               start = mid + 1;
           }
       }
       
       return result;
    }
};