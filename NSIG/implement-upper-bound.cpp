class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = n;
        int start = 0;
        int end = n - 1;
        
        while (start <= end){
            int mid = start + (end - start)/2;
            if (arr[mid] == target){
                ans = mid + 1;
                start = mid + 1;
            }
            else if (arr[mid] > target){
                end = mid - 1;
            }
            else {
                ans = mid + 1;
                start = mid + 1;
            }
        }
        
        return ans;
    }
};