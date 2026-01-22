class Solution {
  public:
    int merge(vector<int> &arr, int left, int mid, int right){
        int i = left;
        int j = mid + 1;
        vector<int> temp;
        int inv = 0;
        while (i <= mid && j <= right){
            if (arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                inv += mid - i + 1;
                j++;
            }
        }
        
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);
        
        for (int i = left; i <= right; i++){
            arr[i] = temp[i - left];
        }
        
        return inv;
    }
    int mergeSort(vector<int> &arr, int left, int right){
        if (left >= right) return 0;
        int mid = left + (right - left)/2;
        int inv = 0;
        inv += mergeSort(arr, left, mid);
        inv += mergeSort(arr, mid + 1, right);
        inv += merge(arr, left, mid, right);
        
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