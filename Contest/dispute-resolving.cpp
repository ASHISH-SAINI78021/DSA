#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxi = 1;
    for (int i = 0; i < n; i++){
        int start = i; int end = i;
        while (start >= 0 && end < n && s[start] == s[end]){
            maxi = max(maxi, end - start + 1);
            start--; end++;
        }
        start = i; end = i + 1;
        while (start >= 0 && end < n && s[start] == s[end]){
            maxi = max(maxi, end - start + 1);
            start--; end++;
        }
    }
    
    cout << maxi << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}