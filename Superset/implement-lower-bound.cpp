class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int ans = n;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (target == arr[mid]){
                ans = mid;
                end = mid - 1;
            }
            else if (arr[mid] > target){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return ans;
    }
};