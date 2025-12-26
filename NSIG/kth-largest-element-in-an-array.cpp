class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return *max_element(nums.begin(), nums.end());
        priority_queue<int, vector<int>, greater<int>> pq;  // minheap

       
       for (int i = 0; i < k && i < n; i++){
            pq.push(nums[i]);
       }
       for (int i = k; i < n; i++){
            if (nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
       }

       return pq.top();
    }
};


// nums = 3 2 1 5 6 4    k = 2
// Approach 
// (n - k)th smallest element would be the kth largest element.
// T.C -> O(nlogk)
// S.C -> O(k)

// edge cases
// k = 1 -> *max_element()