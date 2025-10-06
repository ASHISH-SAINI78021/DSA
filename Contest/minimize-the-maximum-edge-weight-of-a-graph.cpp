#include <vector>
#include <algorithm>
#include <queue>

class Solution {
private:
    bool check(int max_weight, int n, int threshold, const std::vector<std::vector<int>>& sorted_edges) {
        std::vector<std::vector<int>> rev_adj(n);
        
        // THE FIX (Part 2): Break early from the loop.
        for (const auto& edge : sorted_edges) {
            if (edge[2] > max_weight) {
                break; // Since edges are sorted, no need to check the rest.
            }
            rev_adj[edge[1]].push_back(edge[0]);
        }

        std::queue<int> q;
        q.push(0);
        std::vector<bool> visited(n, false);
        visited[0] = true;
        std::vector<int> in_degree_used(n, 0);
        int nodes_reached = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : rev_adj[u]) {
                if (in_degree_used[v] < threshold) {
                    in_degree_used[v]++;
                    if (!visited[v]) {
                        visited[v] = true;
                        nodes_reached++;
                        q.push(v);
                    }
                }
            }
        }
        return nodes_reached == n;
    }

public:
    int minMaxWeight(int n, std::vector<std::vector<int>>& edges, int threshold) {
        // THE FIX (Part 1): Sort the edges array by weight ONCE.
        std::sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });

        int low = 0;
        int high = 1e9 + 7;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Pass the sorted edges to the check function.
            if (check(mid, n, threshold, edges)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};©leetcode