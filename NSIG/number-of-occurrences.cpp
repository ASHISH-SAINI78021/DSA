class Solution {
  public:
    int lastOcc(vector<int> &arr, int start, int end, int &target){
        int ans = -1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (arr[mid] == target){
                ans = mid;
                start = mid + 1;
            }
            else if (arr[mid] > target){
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return ans;
    }
    int firstOcc(vector<int> &arr, int start, int end, int &target){
        int ans = -1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (arr[mid] == target){
                ans = mid;
                end = mid - 1;
            }
            else if (arr[mid] > target){
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int first = firstOcc(arr, start, end, target);
        int last = lastOcc(arr, start, end, target);
        
        if (first == -1 && last == -1) return 0;
        if (first == -1 || last == -1) return 1;
        
        return last - first + 1;
    }
};
