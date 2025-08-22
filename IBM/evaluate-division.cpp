#include <bits/stdc++.h>
using namespace std;

vector<double> evaluateEquations(vector<pair<string, string>> &equations, vector<pair<string, string>> &queries, vector<double> &values) {
    int n = equations.size();
    unordered_map<string, vector<pair<string,double>>> adj;
    vector<double> ans;

    // Build adjacency list
    for (int i = 0; i < n; i++){
        string u = equations[i].first;
        string v = equations[i].second;
        adj[u].push_back({v, values[i]});
        adj[v].push_back({u, 1.0 / values[i]});
    }

    // Process queries
    for (int i = 0; i < queries.size(); i++){
        string src = queries[i].first;
        string dst = queries[i].second;

        if (adj.find(src) == adj.end() || adj.find(dst) == adj.end()){ 
            ans.push_back(-1.0);
            continue;
        }

        unordered_map<string, int> visited;
        queue<pair<string,double>> q;
        q.push({src, 1.0});
        visited[src] = 1;
        bool check = true;

        while (!q.empty()){
            auto front = q.front(); q.pop();
            string node = front.first;
            double fac = front.second;

            if (node == dst){
                ans.push_back(fac);
                check = false;
                break;
            }

            for (auto it: adj[node]){
                string v = it.first;
                double wt = it.second;
                if (!visited[v]){
                    q.push({v, fac * wt});
                    visited[v] = 1;
                }
            }
        }
        if (check) ans.push_back(-1.0);
    }

    return ans;
}
