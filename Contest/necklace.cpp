#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + n - k);
    reverse(arr.begin() + n - k, arr.end());
    
    for (auto it : arr) cout << it << " ";
    cout << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--){
	    solve();
	}
	
	return 0;
}
