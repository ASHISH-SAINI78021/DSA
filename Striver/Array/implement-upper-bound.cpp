class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int ans = n;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (arr[mid] <= target){
                ans = mid + 1;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return ans;
    }
};
