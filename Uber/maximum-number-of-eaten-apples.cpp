#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    int count;
    int dead;
    Node(int count, int dead) {
        this->count = count;
        this->dead = dead;
    }
};

// Priority queue with custom comparator
struct Compare {
    bool operator()(const Node &a, const Node &b) {
        return a.dead > b.dead;  // min-heap by expiry
    }
};

int maxEatenApples(int n, vector<int> &apples, vector<int> &days) {
    priority_queue<Node, vector<Node>, Compare> pq;
    int eaten = 0;

    for (int i = 0; i < n || !pq.empty(); i++) {
        // Add today?s apples
        if (i < n && apples[i] > 0) {
            pq.push(Node(apples[i], i + days[i]));
        }

        // Remove expired
        while (!pq.empty() && pq.top().dead <= i) {
            pq.pop();
        }

        // Eat one apple
        if (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();
            eaten++;
            curr.count--;
            if (curr.count > 0) {
                pq.push(curr);
            }
        }
    }
    return eaten;
}
