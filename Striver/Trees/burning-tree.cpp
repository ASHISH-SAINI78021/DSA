class Solution {
  public:
    int time = 0;
    void solve(Node* root, unordered_map<Node*, Node*> &mp, unordered_map<Node*, bool> &visited){
        // base case
        if (root == NULL || visited[root]) return ;
        
        // solution for one case
        time++;
        visited[root] = true;
        solve(root->left, mp, visited);
        solve(root->right, mp, visited);
        solve(mp[root], mp, visited);
    }
    int minTime(Node* root, int k) {
        if (root == NULL) return 0;
        unordered_map<Node*, Node*> mp;
        unordered_map<Node*, bool> visited;
        Node* target;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            auto front = q.front();q.pop();
            if (front->data == k) target = front;
            if (front->left){
                q.push(front->left);
                mp[front->left] = front;
            }
            if (front->right){
                q.push(front->right);
                mp[front->right] = front;
            }
        }
        
        solve(target, mp, visited);
        
        return time;
    }
};