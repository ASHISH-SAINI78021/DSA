class Solution {
public:
    double myPow(double x, int power) {
        // base case
        long long n = power;
        if (n < 0){
            x = 1/x;
            n = -n;
        }
        if (n == 0) return 1;

        // solution for one case

        if (n % 2 == 0){
            return myPow(x*x, n/2);
        }
        else {
            return x*myPow(x*x, (n - 1)/2);
        }
    }
};