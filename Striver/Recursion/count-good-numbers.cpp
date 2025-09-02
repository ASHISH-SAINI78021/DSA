class Solution {
public:
    const int mod = 1e9 + 7;
    long long solve(long long x, long long n){
        // base case
        if (n == 0) return 1;
        
        // solution for one case
        if (n % 2 == 0) return (solve((x*x) % mod, n/2)) % mod;
        else return (x*solve((x*x) % mod, (n - 1)/2)) % mod;
    }
    int countGoodNumbers(long long n) {
        long long ans = 0;
        int even = 5;
        int prime = 4;
        if (n == 1) return 5;

        if (n % 2 == 0){
            ans = ((solve(even, n/2) % mod)*(solve(prime, n/2) % mod)) % mod;
        }
        else {
            ans = ((solve(even, n/2 + 1) % mod)*(solve(prime, n/2) % mod)) % mod;
        }

        return ans;
    }
};