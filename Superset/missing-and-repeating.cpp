class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        // x -> missing number
        // y -> repeating number
        long long sn = 1LL*n*(n + 1)/2;
        long long s2n = 1LL*n*(n + 1)*(2*n + 1)/6;
        long long s = accumulate(arr.begin(), arr.end(), 1LL*0);
        long long s2 = 0;
        for (int i = 0; i < n; i++){
            s2 += 1LL*arr[i]*arr[i];
        }
        
        int val1 = s - sn;
        int val2 = (s2 - s2n)/(s - sn);
        
        int x = (val1 + val2)/2;
        int y = x - val1;
        
        return {x, y};
    }
};