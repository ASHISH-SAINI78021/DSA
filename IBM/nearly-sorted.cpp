#include <bits/stdc++.h> 
vector<int> nearlySorted(vector<int> arr, int n, int k) {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++){
        pq.push(arr[i]);
        if (pq.size() > k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    while (!pq.empty()){
        int top = pq.top();pq.pop();
        ans.push_back(top);        
    }

    return ans;
}