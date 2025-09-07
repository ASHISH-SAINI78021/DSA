// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<int> pq;
        for (int i = 0; i < k && i < n; i++) pq.push(arr[i]);
        
        for (int i = k; i < n; i++){
            if (arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};