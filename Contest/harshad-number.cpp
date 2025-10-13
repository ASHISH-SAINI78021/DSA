class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int n = x;
        while (n > 0){
            int rem = n % 10;
            sum += rem;
            n = n/10;
        }

        return (x % sum == 0) ? sum : -1;
    }
};