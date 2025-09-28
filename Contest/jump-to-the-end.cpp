#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int last = 0;
    int jumps = 0;
    for (int i = n - 1; i >= 0; i--){
        if (arr[i] + i >= last){
            last = i;
            jumps++;
        }
    }
    if (last != 0){
        cout << -1 << endl;
        return ;
    }
    
    cout << jumps - 1 << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--){
	    solve();
	}
	
	return 0;
}
