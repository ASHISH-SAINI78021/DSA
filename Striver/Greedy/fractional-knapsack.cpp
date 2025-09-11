class Node {
public:
    int value;
    int weight;
    double ratio;

    Node(int value, int weight) {
        this->value = value;
        this->weight = weight;
        this->ratio = (double)value / (double)weight;
    }
};

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        double ans = 0.0;
        int n = val.size();
        vector<Node*> items;
        
        // Create Node objects
        for (int i = 0; i < n; i++) {
            Node* temp = new Node(val[i], wt[i]);
            items.push_back(temp);
        }
        
        // Sort by ratio descending
        sort(items.begin(), items.end(), [](Node* a, Node* b) {
            return a->ratio > b->ratio;
        });
        
        // Pick items
        for (int i = 0; i < n; i++) {
            Node* temp = items[i];
            if (temp->weight <= capacity) {
                ans += (double)temp->value;
                capacity -= temp->weight;
            } else {
                ans += temp->ratio * (double)capacity;
                break;
            }
        }
        
        return ans;
    }
};
