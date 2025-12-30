class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        long long sn = 1LL*n*(n + 1)/2;
        long long s2n = 1LL*n*(n + 1)*(2*n + 1)/6;
        long long s = 0;
        long long s2 = 0;
        for (int i = 0; i < n; i++){
            s += arr[i];
            s2 += 1LL*arr[i]*arr[i];
        }
        
        long long val1 = s - sn;
        long long val2 = s2 - s2n;
        val2 = val2/val1;
        long long x = (val1 + val2)/2;
        long long y = x - val1;
        
        return {(int)x, (int)y};
    }
};