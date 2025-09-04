#include <stdio.h>

int main() {
	int t;
	cin >> t;
	
	while (t--){
	    int n;
	    cin >> n;
	    vector<int> arr(n);
	    for (int i = 0; i < n; i++) cin >> arr[i];
	    int mini = INT_MAX;
	    long long ans = 0;
	    for (int i = 0; i < n; i++){
	        mini = min(mini, arr[i]);
	        ans += mini;
	    }
	    cout << ans << endl;
	}
}