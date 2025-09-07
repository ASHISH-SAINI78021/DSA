
class Solution {
  public:
    bool heapify(int arr[], int i, int n){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        
        if (largest != i){
            return false;
        }
        return true;
    }
    bool isMaxHeap(int arr[], int n) {
        for (int i = n/2 - 1; i >= 0; i--){
            if (!heapify(arr, i, n)){
                return false;
            }
        }
        
        return true;
    }
};