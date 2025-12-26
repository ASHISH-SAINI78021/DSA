// User function Template for C++

class Solution {
  public:
    void heapify(vector<int> &arr, int i, int n){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        
        if (largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, largest, n);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int n) {
        for (int i = n/2; i >= 0; i--){
            heapify(arr, i, n);
        }
    }
};

// T.C -> O(nlogn)
// S.C -> O(1)
