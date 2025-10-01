#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; 
    int x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    multiset<int> st;
    for (int r = 0; r < n; r++){
        st.insert(arr[r]);
        if (st.size() == x){
            cout << *(--st.end()) << " ";
            st.erase(st.find(arr[r - x + 1]));
        }
    }
    cout << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}