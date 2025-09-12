#include<bits/stdc++.h>
using namespace std;
vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
    vector<int> ans;
    int n = arr.size();
    int l = 0;
    unordered_map<int, int> mp;
    int mini = INT_MAX;
    int start = -1;
    int end = -1;
    if (k > n) return {-1};

    for (int r = 0; r < n; r++){
        mp[arr[r]]++;
        while (mp.size() > k){
            mp[arr[l]]--;
            if (mp[arr[l]] == 0){
                mp.erase(arr[l]);
            }
            l++;
        }
        if (mp.size() == k){
            while (mp[arr[l]] > 1){
                mp[arr[l]]--;
                l++;
            }
            if (r - l + 1 < mini){
                mini = r - l + 1;
                start = l;
                end = r;
            }
        }
    }

    if (start == -1 || end == -1) return {-1};

    return {start, end};
}
