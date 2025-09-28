#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n), brr;
    stack<int> st;

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= arr[i]) {
            brr.push_back(st.top());
            st.pop();
        }
        st.push(arr[i]);
    }

    while (!st.empty()) {
        brr.push_back(st.top());
        st.pop();
    }
    for (int i = 1; i < n; i++) {
        if (brr[i - 1] > brr[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
