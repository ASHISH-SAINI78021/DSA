class Solution {
public:
    void solve(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, unordered_map<TreeNode*, bool> &visited, vector<int> &ans, int k){
        if (root == NULL || visited[root]) return ;
        if (k == 0){
            ans.push_back(root->val);
            return ;
        }
        visited[root] = true;
        solve(root->left, parent, visited, ans, k - 1);
        solve(root->right, parent, visited, ans, k - 1);
        solve(parent[root], parent, visited, ans, k - 1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (root == NULL) return ans;
        TreeNode* t = NULL;
        unordered_map<TreeNode*, TreeNode*> mp;
        mp[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            auto front = q.front(); q.pop();
            if (front == target){
                t = front;
            }
            
            if (front->left){
                q.push(front->left);
                mp[front->left] = front;
            }
            if (front->right){
                q.push(front->right);
                mp[front->right] = front;
            }
        }

        unordered_map<TreeNode*, bool> visited;
        solve(target, mp, visited, ans, k);

        return ans;
    }
};