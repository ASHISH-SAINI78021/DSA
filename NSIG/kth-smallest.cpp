class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<int> pq;
        for (int i = 0; i < k && i < n; i++){
            pq.push(arr[i]);
        }
        
        for (int i = k; i < n; i++){
            if (arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};



// Naive Approach
// T.C -> O(nlogn) -> inplace merge sort
// S.C -> O(1)// constant

// second Approach
// push all the elements
// pop n - k elements
// return pq.top();
// T.C -> O(nlogn)
// S.C -> O(n)

// Optimal Approach
// T.C -> O(nlogk)
// S.C -> O(k)
