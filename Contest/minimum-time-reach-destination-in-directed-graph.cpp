class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<tuple<int, int, int>>> adj(n);
        vector<int> dist(n, 1e9);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int start = edges[i][2];
            int end = edges[i][3];
            adj[u].push_back({v, start, end});
        }

        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty()){
            auto top = pq.top(); pq.pop();
            int time = top.first;
            int node = top.second;

            if (time > dist[node]) continue ;
            if (node == n - 1) return time;

            for (auto it : adj[node]){
                auto [v, start, end] = it;
                if (time > end) continue; 
                int depart = max(start, time);
                int arrival = depart + 1;
                if (arrival < dist[v]){
                    dist[v] = arrival;
                    pq.push({arrival, v});
                }
            }
        }


        return -1;
    }
};