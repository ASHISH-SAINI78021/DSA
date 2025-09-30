#include <bits/stdc++.h>
using namespace std;
void solve(){
    string a;
    string b;
    cin >> a;
    cin >> b;
    
    int ans = a.find(b) == string::npos;
    if (ans) cout << 0 << endl;
    else cout << 1 << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
