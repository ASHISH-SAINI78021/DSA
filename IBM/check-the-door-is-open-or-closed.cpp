#include <bits/stdc++.h> 
string doorStatus(int n) {
    string ans(n, '0');
    for (int i = 1; i*i <= n; i++){
        ans[i*i - 1] = '1';
    }

    return ans;
}