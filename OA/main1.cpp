#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, target;
    cin >> n >> target; 
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    unordered_map<int, int> mp;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        if (sum == target) count++;
        int remaining = sum - target;
        if (mp.find(remaining) != mp.end()){
            count += mp[remaining];
        }
        mp[sum]++;
    }

    cout << count << endl;
    return 0;
}