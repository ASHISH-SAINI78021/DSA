class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int sign = 1;
        long long num = 0;
        while (s[i] == ' ') i++;
        if (s[i] == '-' || s[i] == '+'){
            if (s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        while (s[i] == '0') i++;
        while (i < n && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i] - '0');
            if (num > INT_MAX && sign == 1) return INT_MAX;
            if (num > INT_MAX && sign == -1) return INT_MIN;
            i++;
        }
        // int reversedNum = 0;
        // while (num > 0){
        //     int rem = num % 10;
        //     reversedNum = reversedNum*10 + rem;
        //     num = num/10;
        // }

        return sign*num;
    }
};