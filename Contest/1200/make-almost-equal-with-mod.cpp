#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        using ll = long long;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        ll ans = 0;
        for (int i = 1; i <= 60; i++){
            ll k = 1LL << i;
            set<ll> st;
            for (int ind = 0 ; ind < n; ind++){
                st.insert(arr[ind]%k);
            }
            if (st.size() == 2){
                ans = k;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}