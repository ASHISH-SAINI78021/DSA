#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxSubArray(const vector<int> &arr){
    int n = arr.size();
    using ll = long long;
    ll maxi = INT_MIN;
    ll sum = 0;
    
    // kadane's Algo
    for (int i = 0; i < n; i++){
        sum += arr[i];
        maxi = max(sum, maxi);
        if (sum < 0) sum = 0;
    }

    return maxi;
}
int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = maxSubArray(arr);
    cout << "Maximum sum : " << ans << endl;
    return 0;
}