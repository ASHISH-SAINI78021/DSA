class Solution {
  public:
    int minTime(Node* root, int t) {
        if (root == NULL) return 0;
        queue<Node*> q;
        Node* target;
        q.push(root);
        unordered_map<Node*, Node*> mp;
        unordered_map<Node*, bool> visited;
        mp[root] = NULL;
        while (!q.empty()){
            auto front = q.front(); q.pop();
            if (front->data == t) target = front;
            if (front->left){
                q.push(front->left);
                mp[front->left] = front;
            }
            if (front->right){
                q.push(front->right);
                mp[front->right] = front;
            }
        }
        
        int time = 0;
        using T = pair<Node*, int>;
        queue<T> q1;
        q1.push({target, 0});
        visited[target] = true;
        while (!q1.empty()){
            auto front = q1.front(); q1.pop();
            auto node = front.first;
            int cost = front.second;
            time = max(time, cost);
            if (node->left && !visited[node->left]){
                q1.push({node->left, cost + 1});
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right]){
                q1.push({node->right, cost + 1});
                visited[node->right] = true;
            }
            if (mp[node] && !visited[mp[node]]){
                q1.push({mp[node], cost + 1});
                visited[mp[node]] = true;
            }
        }
        
        return time;
    }
};