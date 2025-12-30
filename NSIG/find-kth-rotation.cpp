class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int p = -1;
        int start = 0;
        int end = n - 1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (mid > 0 && arr[mid - 1] > arr[mid]) return mid;
            if (mid + 1 < n && arr[mid + 1] < arr[mid]) return mid + 1;
            
            if (arr[mid] >= arr[start]) start = mid + 1;
            else end = mid - 1;
        }
        
        return 0;
    }
};
