class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int sign = 1;
        int i = 0;
        long long value = 0;

        while (i < n && s[i] == ' ') i++;
        if (s[i] == '+' || s[i] == '-'){
            if (s[i] == '-'){
                sign = -1;
            }
            i++;
        }

        while (i < n && isdigit(s[i])){
            value = value*10 + (s[i] - '0');
            if (value > INT_MAX && sign == 1) return INT_MAX;
            if (value > INT_MAX && sign == -1) return INT_MIN;
            i++;
        }

        return sign*value;
    }
};