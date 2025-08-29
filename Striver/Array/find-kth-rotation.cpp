class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (mid > 0 && arr[mid] < arr[mid - 1]) return mid;
            if (mid + 1 < n && arr[mid] > arr[mid + 1]) return mid + 1;
            if (arr[mid] >= arr[start]) start = mid + 1;
            else end = mid - 1;
        }
        
        return 0;
    }
};
