class Solution {
  public:
    int nthRoot(int n, int m) {
        int start = 0;
        int end = m;
        int ans = -1;
        
        while (start <= end){
            int mid = start + (end - start)/2;
            double target = pow(mid, n);
            if (target <= m){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        
        return ans;
    }
};

// Time Complexity : O(nlogm)