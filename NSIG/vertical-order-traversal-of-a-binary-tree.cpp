class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        using T = pair<int, pair<int, TreeNode*>>;

        queue<T> q;
        q.push({0, {0, root}}); // {col, {row, node}};
        map<int, map<int, multiset<int>>> mp;

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int col = front.first;
            int row = front.second.first;
            TreeNode* node = front.second.second;

            mp[col][row].insert(node->val);
            if (node->left){
                q.push({col - 1, {row + 1, node->left}});
            }
            if (node->right){
                q.push({col + 1, {row + 1, node->right}});
            }
        }

        for (auto it : mp){
            vector<int> vline;
            for (auto col : it.second){
                for (auto ele : col.second){
                    vline.push_back(ele);
                }
            }
            ans.push_back(vline);
        }

        return ans;
    }
};