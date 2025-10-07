#include<iostream>
#include<vector>
#include<string>
using namespace std;
int linearSearch(const vector<int> &arr, int &target){
    int n = arr.size();
    for (int i = 0; i < n; i++){
        if (arr[i] == target) return i;
    }

    return -1;
}
void solve(){
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = linearSearch(arr, target);
    cout << "Linear search : " << ans << endl;
    
}
int main(){
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}