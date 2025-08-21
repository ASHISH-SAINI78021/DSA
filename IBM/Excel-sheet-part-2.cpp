#include <bits/stdc++.h> 
using ll = long long;
long long titleToNumber(string str) {
    int n = str.length();
    ll ans = 0;
    ll sum = 0;
    int k = 0;
    int freq[26];
    for (int i = 0; i < 26; i++) freq[i] = i + 1;
    for (int i = n - 1; i >= 0; i--){
        if (str[i] == ' '){
            ans += sum;
            sum = 0;
            k = 0;
        }
        else {
            sum += (ll)pow(26, k)*freq[str[i] - 'A'];
            k++;
        }
    }
    
    if (sum != 0) ans += sum;

    return ans;
}