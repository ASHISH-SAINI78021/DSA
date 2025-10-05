#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int> &heights){
    int n = heights.size();
    if (n == 0) return 0;
    vector<int> prev(n);
    vector<int> next(n);
    prev[0] = heights[0];
    for (int i = 1; i < n; i++){
        prev[i] = max(prev[i - 1], heights[i]);
    }
    next[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; i--){
        next[i] = max(next[i + 1], heights[i]);
    }

    int totalArea = 0;
    for (int i = 0; i < n; i++){
        totalArea += min(prev[i], next[i]) - heights[i];
    }

    return totalArea;
}
int main(){
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = maxArea(heights);
    cout << "Maximum area covered by the barriers : " << ans << endl;
    return 0;
}