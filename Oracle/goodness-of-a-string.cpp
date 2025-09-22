#include <bits/stdc++.h> 
int goodnessOfString(string &s)
{
    int n = s.length();
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; ){
        if (s[i] == '['){
            count++;
        }
        else if (isdigit(s[i])){
            int ans = 0;
            while (isdigit(s[i])){
                ans = ans*10 + (s[i] - '0');
                i++;
            }
            sum = sum + ans*count;
            continue ;
        }
        else if (s[i] == ']') count--;
        i++;
    }

    return sum;
}