class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                auto front = q.front();q.pop();
                if (i == size - 1) ans.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }

        return ans;
    }
};