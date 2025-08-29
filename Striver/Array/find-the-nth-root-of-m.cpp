class Solution {
  public:
    int nthRoot(int n, int m) {
        int start = 1;
        int end = m;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (pow(mid, n) == m) return mid;
            else if (pow(mid, n) > m) end = mid - 1;
            else start = mid + 1;
        }
        
        return -1;
    }
};