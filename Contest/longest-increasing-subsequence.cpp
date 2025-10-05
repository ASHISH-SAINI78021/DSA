#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> tail;
    for (int i = 0; i < n; i++){
        if (!tail.empty()){
            if (tail.back() < arr[i]){
                tail.push_back(arr[i]);
            }
            else {
                auto it = lower_bound(tail.begin(), tail.end(), arr[i]);
                *it = arr[i];
            }
        }
        else {
            tail.push_back(arr[i]);
        }
    }

    return tail.size();
}