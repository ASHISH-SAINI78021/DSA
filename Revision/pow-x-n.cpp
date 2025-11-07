class Solution {
public:
    double myPow(double x, int power) {
        long long n = power;
        // base case
        if (n == 0) return 1;
        if (n < 0){
            x = 1/x;
            n = -n;
        }

        // solution for one case
        if (n % 2 == 0){
            return myPow(x*x, n/2);
        }
        else {
            return x*myPow(x*x, (n - 1)/2);
        }
    }
};