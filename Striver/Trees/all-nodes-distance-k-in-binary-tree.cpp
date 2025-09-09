class Solution {
public:
    void solve(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp, vector<int> &ans, int k, unordered_map<TreeNode*, bool> &visited){
        // base case
        if (root == NULL || visited[root]) return ;
        if (k == 0){
            ans.push_back(root->val);
            return ;
        }

        // solution for one case
        visited[root] = true;
        solve(root->left, mp, ans, k - 1, visited);
        solve(root->right, mp, ans, k - 1, visited);
        solve(mp[root], mp, ans, k - 1, visited);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (root == NULL) return ans;
        unordered_map<TreeNode*, TreeNode*> mp;

        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;
        while (!q.empty()){
            auto front = q.front(); q.pop();
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

        solve(target, mp, ans, k, visited);

        return ans;
    }
};