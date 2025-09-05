#include <bits/stdc++.h> 
vector<int> exclusiveTime(vector<vector<int>> &logs, int k, int l) 
{
    vector<int> result(k, 0);
    int n = logs[0].size();
    stack<int> st;
    int prevTime = logs[0][2];


    for (int i = 0; i < n; i++){
        int type = logs[1][i];
        int time = logs[2][i];
        int func = logs[0][i];

        if (!st.empty()){
            result[st.top()] += time - prevTime;
        }

        if (type == 1){
            st.push(func);
        }
        else {
            result[st.top()]++;
            st.pop();
        }
        prevTime = time + (type == -1 ? 1 : 0);
    }

    return result;
}