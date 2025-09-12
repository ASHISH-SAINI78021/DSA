#include <bits/stdc++.h> 
int taskScheduler(string tasks, int n, int t) {
    int time = 0;
    priority_queue<int> pq;
    unordered_map<char, int> mp;
    for (int i = 0; i < tasks.length(); i++) mp[tasks[i]]++;
    for (auto it : mp) pq.push(it.second);

    while (!pq.empty()){
        vector<int> temp;
        for (int i = 1; i <= t + 1; i++){
            if (!pq.empty()){
                int top = pq.top();pq.pop();
                top--;
                temp.push_back(top);
            }
        }
        for (int i = 0; i < temp.size(); i++){
            if (temp[i] != 0) pq.push(temp[i]);
        }
        if (pq.empty()) time += temp.size();
        else time += t + 1;
    }

    return time;
}