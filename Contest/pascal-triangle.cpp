#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long> arr;
    if (n == 1){
        cout << 1 << endl;
        return ;
    }
    if (n == 2){
        cout << 1 << " "; cout << 1 << " " << endl;
        return ;
    }
    arr = {1, 1};
    vector<long long> temp;
    for (int i = 3; i <= n; i++){
        temp.push_back(1);
        for (int j = 1; j < arr.size(); j++){
            temp.push_back(arr[j] + arr[j - 1]);
        }
        temp.push_back(1);
        arr = temp;
        temp.clear();
    }
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
	int t; 
	cin >> t;
	while (t--) solve();
	
	return 0;
}