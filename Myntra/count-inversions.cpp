class Solution {
  public:
    int mergeCount(vector<int> &arr, int left, int mid, int right){
        vector<int> temp;
        int i = left; int j = mid + 1;
        int inv = 0;
        while (i <= mid && j <= right){
            if (arr[j] >= arr[i]){
                temp.push_back(arr[i++]);
            }
            else {
                temp.push_back(arr[j++]);
                inv += (mid - i + 1);
            }
        }
        
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);
        
        for (int k = left; k <= right; k++){
            arr[k] = temp[k - left];
        }
        
        return inv;
    }
    int mergeSort(vector<int> &arr, int left, int right){
        // base case
        if (left >= right) return 0;
        
        // solution for one case
        int inv = 0;
        int mid = left + (right - left)/2;
        inv += mergeSort(arr, left, mid);
        inv += mergeSort(arr, mid + 1, right);
        inv += mergeCount(arr, left, mid, right);
        
        return inv;
    }
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        int ans = mergeSort(arr, left, right);
        
        return ans;
    }
};