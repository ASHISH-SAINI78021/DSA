#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0;
    int end = 0;
    int ansStart = -1;
    for (int i = 0; i < n; i++){\
        if (sum == 0) start = i;
        sum += arr[i];
        if (sum > maxi){
            maxi = sum;
            ansStart = start;
            end = i;
        }
        if (sum < 0){
            sum = 0;
        }
    }
    cout << maxi << endl;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    solve(arr);
    cout << "Maximum subarray sum : " << maxi << endl;
    cout << "Start index : " << ansStart << endl;
    cout << "End index : " << end << endl;
    cout << "Subarray : ";
    for (int i = ansStart; i <= end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}