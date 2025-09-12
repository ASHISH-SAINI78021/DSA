#include <bits/stdc++.h> 
using namespace std;
int maxLengthChain(vector<pair<int, int>> &p, int n) {
    int maxi = 1;
    sort(p.begin(), p.end(), [](pair<int,int> &a, pair<int,int> &b){
        return a.second <= b.second;
    });
    int count = 1;
    int lastIndex = p[0].second;
    for (int i = 0; i < n; i++){
        if (p[i].first > lastIndex){
            count++;
            lastIndex = p[i].second;
        }
        maxi = max(maxi, count);
    }

    return maxi;
}