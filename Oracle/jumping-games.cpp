class Solution {
  public:
    void solve(long long n, long long num, long long &ans){
        // base  case
        if (n >= num){
            ans = max(ans, num);
            // return ;
        }
        if (n < num) return ;
        
        // solution for one case
        for (int i = 0; i <= 9; i++){
            if (abs(num % 10 - i) == 1){
                solve(n , num*10 + i, ans);
            }
        }
    }
    long long jumpingNums(long long n) {
        long long ans = INT_MIN;
        if (n == 0) return 0;
        for (int i = 1; i <= 9; i++){
            solve(n, i, ans);
        }
        
        return ans == INT_MIN ? 0 : ans;
    }
};